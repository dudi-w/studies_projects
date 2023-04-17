#include "TCPserver.hpp"
#include "TCPsocketFile.hpp"

#include <iostream>

int main()
{
    se::TCPserver server(8080);
    std::cout<<"server" <<std::endl;
    server.createSocket();
    std::cout<<"createSocket" <<std::endl;
    server.bindSocket();
    std::cout<<"bindSocket" <<std::endl;
    server.listenForClient();
    std::cout<<"listenForClient" <<std::endl;
    auto fd = server.acceptToReceive();
    std::cout<<"acceptToReceive" <<std::endl;
    fd.read();
    auto reqest = fd.returnAsRequest().getRequest();
    std::cout<<"reqest:"<<std::endl;
    for( auto& q : reqest){
        std::cout<<q<<std::endl;
    }




    return EXIT_SUCCESS;
}