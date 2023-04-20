#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <memory>

#include "TCPserver.hpp"
#include "myExceptions.hpp"

se::TCPserver::TCPserver(uint16_t port)
: m_port(port)
{}

se::TCPserver::~TCPserver()
{
    closeSocket();
}

void se::TCPserver::createSocket()
{
    if((m_server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        throw se::CreateSocketError("failed to create socket");
    }
    // int opt = 1;
    // if(setsockopt(m_server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
    //     throw se::CreateSocketError("failed to create socket");//TODO massge
    // }
}

void se::TCPserver::bindSocket()
{
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(m_port);
    if(bind(m_server_fd, (struct sockaddr*)&m_address, sizeof(m_address))< 0){
        throw se::BindingSocketError("Bind failure");
    }
}

void se::TCPserver::listenForClient() const
{
    if(listen(m_server_fd, SOMAXCONN) < 0){
        throw se::listenError("Listen failure");
    }
}

std::unique_ptr<se::TCPsocketFile> se::TCPserver::acceptTorecieve() const
{
    int clientFileDesciptor;//?
    struct sockaddr_in clientAddress;
    int addrlen = sizeof(m_address);
    if((clientFileDesciptor = accept(m_server_fd, (struct sockaddr*)&clientAddress, (socklen_t*)&addrlen)) < 0){
        throw se::acceptError("Accept failure");
    }
    logConnect(clientAddress);
    return std::make_unique<se::TCPsocketFile>(clientFileDesciptor);
}

void se::TCPserver::closeSocket() const
{
    close(m_server_fd);
    std::cout << "Socket colsed = "<<m_server_fd<<std::endl;
}

void se::TCPserver::logConnect(struct sockaddr_in& clientAddress) const
{
    std::string ipAddress;
    // ipAddress.reserve(INET_ADDRSTRLEN);
    ipAddress.resize(INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(clientAddress.sin_addr), ipAddress.data(), INET_ADDRSTRLEN);
    // ipAddress.resize((strlen(ipAddress.data())));//?
    std::clog << "connect to client\n\tClient IP address is: " << ipAddress << "\n\tClient port is:"<<clientAddress.sin_port<<std::endl;
}
