#include <iomanip>
#include <locale>

#include "textUI.hpp"

se::TextUI::TextUI()
: m_checkInput("(?=[^_])\\b(?:\\w+){3,}\\b(?:\\b|\\s)")
{}

std::unique_ptr<se::Request> se::TextUI::makeRequest() const
{
    std::string request;
    std::cout<<"\033[1;36mEnter your requirement "<<std::ends;
    std::cout<<"\U000027A1 \U000027A1 \U000027A1\n\033[3;37mor Q to exit\033[0m\n"<<std::endl;
    std::getline(std::cin, request);//check of the input is required
    if(request == "Q" || request == "q" ){return nullptr;}
    std::cout<<"The results for the word search \033[1;34m"<<request<<"\033[0m :"<<std::endl;
    return std::make_unique<se::SimpleRequest>(request);
}

void se::TextUI::setAndShowResult(se::Result& result) const
{
    if(result.getResult().size() > 0){
        auto vecResult = result.getResult();
        for(auto& res : vecResult){
            std::cout<<std::left <<" "<<std::setw(90) << res.first<<std::right << std::setw(10) << res.second << std::endl;
        }
    }else{
        std::cout<<"  No results were found for your request \U0001F629 "<<std::endl;
    }
}

