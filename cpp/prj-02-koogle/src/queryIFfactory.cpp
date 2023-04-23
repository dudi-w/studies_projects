#include <iostream>
#include "queryBuilderFactory.hpp"

se::QueryBuilder& se::QueryBuilderFactory::getQueryBuildre()
{
    m_query = nullptr;
    while(true)
    {
        std::cout<<"\033[3;37mto search from command-line pres 'c'\nfrom external source pres 'e'\033[0m"<<std::endl;
        std::string request;
        std::getline(std::cin, request);
        if(request == "c"){
            m_query = std::make_unique<se::TextUI>();
            return *m_query;
        }else if(request == "e"){
            m_query = std::make_unique<se::TCPquerysIF>(8080);
            return *m_query;
        }
        else{
            std::cout<<"Invalid selection"<<std::endl;
        }
    }
}
