#include <iostream>
#include "queryIFfactory.hpp"

se::QuerysIF& se::QueryIFfactory::getIF()
{
    std::string request;
    while(true)
    {
        std::cout<<"\033[3;37mfrom commend-line pres 'c'\nfrom extren pres 'e'\033[0m"<<std::endl;
        std::getline(std::cin, request);
        if(request == "c"){
            return m_tui;
        }
        if(request == "e"){
            return m_tui;//!not correct
        }
        else{
            std::cout<<"inValid"<<std::endl;
        }
    }
}
