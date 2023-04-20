#include <iomanip>
#include <locale>

#include "textUI.hpp"

se::TextUI::TextUI()
: m_checkInput("(?=[^_])\\b(?:\\w+){3,}\\b(?:\\b|\\s)")
{}

std::unique_ptr<se::Request> se::TextUI::makeRequest()
{
    m_request.clear();
    std::cout<<"\033[1;36mEnter your requirement "<<std::ends;
    std::cout<<"\U000027A1 \U000027A1 \U000027A1\n\033[3;37mor Q to exit\033[0m\n"<<std::endl;
    // std::cin >> m_request;
    std::cin>> m_request;
    // std::getline(std::cin, m_request);//check of the input is required
    if(m_request == "Q" || m_request == "q" ){return nullptr;}
    // std::cin >> m_request;
    // std::cout<< __FILE__ << ':' << __LINE__  <<std::endl;
    // std::string temp;
    // std::cin>> temp;
    return std::make_unique<se::SimpleRequest>(m_request);
}

void se::TextUI::recieveResult(se::Result& result) const
{
    if(result.getResult().size() > 0){
        std::cout<<"The results for the word search \033[1;34m"<<m_request<<"\033[0m :"<<std::endl;
        auto vecResult = result.getResult();
        for(auto& res : vecResult){
            std::cout<<std::left <<" "<<std::setw(90) << res.first<<std::right << std::setw(10) << res.second << std::endl;
        }
    }else{
        std::cout<<"  No results were found for your request :\033[1;34m"<<m_request<<"\033[0m \U0001F629"<<std::endl;
    }
}

