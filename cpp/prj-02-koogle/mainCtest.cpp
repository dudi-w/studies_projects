#include "TCPclient.hpp"
#include "TCPsocketFile.hpp"
#include "smartRequest.hpp"
#include <iostream>

int main()
{
    se::TCPclient client("127.0.0.1",8080);
    std::cout<<"client" <<std::endl;
    client.createSocket();
    std::cout<<"createSocket" <<std::endl;
    auto fd = client.connectToServer();
    std::cout<<"connectToServer" <<std::endl;
    se::SmartRequest reqest("kjdf r wfoewrj fowrjferj f jewrpf rpreoj foerj oewrr jl");
    fd.insertAsString(reqest);
    return EXIT_SUCCESS;
}