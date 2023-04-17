#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
// #include <stdio.h>
// #include <string.h>

#include "TCPclient.hpp"
#include "myExceptions.hpp"

se::TCPclient::TCPclient::TCPclient(std::string const& serverAddress, uint16_t port)
: m_serverPort(port)
, m_serverAddress(serverAddress)
{}

se::TCPclient::~TCPclient()
{
    closeSocket();
}

void se::TCPclient::createSocket()
{
    // int status, valread;
    if((m_client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        throw se::CreateSocketError("failed to create socket");
    }
}

se::TCPsocketFile se::TCPclient::connectToServer()
{
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(m_serverPort);

    if (inet_pton(AF_INET, m_serverAddress.c_str(), &serv_addr.sin_addr) <= 0){
        close(m_client_fd);
        throw se::CommunicationError("");//TODO
    }
    int status = connect(m_client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(status < 0){
        close(m_client_fd);
        throw se::CommunicationError("Connection Failed");//TODO
    }
    return se::TCPsocketFile(m_client_fd);
}

void se::TCPclient::closeSocket() const
{
    close(m_client_fd);
}
