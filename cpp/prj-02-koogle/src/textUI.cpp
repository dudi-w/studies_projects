#include <iomanip>
#include <locale>

#include "textUI.hpp"
// #include "re"

se::TextUI::TextUI()
: m_checkInput("(?=[^_])\\b(?:\\w+){3,}\\b(?:\\b|\\s)")
{}

std::unique_ptr<se::Request> se::TextUI::makeRequest() const
{
    std::string request;
    std::cout<<"\033[1;36m Enter a word to search "<<std::ends;
    std::cout<<"\u27A1\033[0m"<<std::endl;
    std::cin>>request;//check of the input is required
    return std::make_unique<se::SimpleRequest>(request);
}

void se::TextUI::setAndShowResult(se::ResultIF& result) const
{
    auto vecResult = result.getResult();
    for(auto& res : vecResult){
        std::cout<<std::left <<std::setw(40) << res.first<<std::endl;
        std::cout<< std::right << std::setw(10) << res.second << std::endl;
    }
}

