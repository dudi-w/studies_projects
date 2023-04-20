#include <iostream>
#include "queryIFfactory.hpp"

se::QuerysIF& se::QueryIFfactory::getIF()
{
    std::string request;
    m_query = nullptr;
    while(true)
    {
        std::cout<<"\033[3;37mfrom commend-line pres 'c'\nfrom extren pres 'e'\033[0m"<<std::endl;
        std::getline(std::cin, request);
        if(request == "c"){
            m_query = std::make_unique<se::TextUI>();
            return *m_query;
        }else if(request == "e"){
            std::cout<<"\033[3;37mEnter port num\033[0m"<<std::endl;
            std::string port;
            std::getline(std::cin, port);
            std::cout<<"\033[3;37mport num\033[0m"<<std::stoi(port)<<std::endl;
            m_query = std::make_unique<se::TCPquerysIF>(std::stoi(port));//TODO
            return *m_query;
        }
        else{
            std::cout<<"inValid"<<std::endl;
        }
    }
}
