#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <nlohmann/json.hpp>
#include <sstream>

#include "TCPsocketFile.hpp"
#include "tools.hpp"

se::TCPsocketFile::TCPsocketFile(int fileDescriptor)
: m_fileDescriptor(fileDescriptor)
, m_buffSize(4096)
{
    // buffer.resize(m_buffSize, 0);
    // ipAddress.resize((strlen(ipAddress.data())));//TODO
}

se::TCPsocketFile::~TCPsocketFile()
{
    colseSocket();
}

std::string se::TCPsocketFile::read()
{
    std::cout<<"read :: m_fileDescriptor"<<m_fileDescriptor<< std::endl;
    std::string message;
    std::cout<<"read "<<m_buffSize<< std::endl;
    message.resize(0,0);
    std::cout<<message<<message.size()<< std::endl;
    int bytesReceived = 0;
    while(true){
        std::string buffer(m_buffSize, 0);
        bytesReceived = recv(m_fileDescriptor, buffer.data(), m_buffSize ,0);
        if(bytesReceived < 0){
            std::cout<<"bytesReceived = "<<bytesReceived<<" "<<buffer<<buffer.size()<< std::endl;
            throw 1;
            break;//TODO thrwo exception
        }
        message.append(buffer ,0 ,bytesReceived);
        if(bytesReceived < m_buffSize && bytesReceived){
            std::cout<<"bytesReceived = "<<bytesReceived<<" "<<message<<"message.size()"<<message.size()<< std::endl;
            break;
        }
    }
    std::cout<<"and read : "<<message<<message.size()<< std::endl;
    return message;
}

void se::TCPsocketFile::write(std::string const& text) const
{
    std::cout<<"write :: m_fileDescriptor"<<m_fileDescriptor<< std::endl;
    if(ssize_t bytesSent = send(m_fileDescriptor, text.c_str(), text.size(), 0); bytesSent < 0){
        //TODO throw
    }
    std::cout << "se::TCPsocketFile::write" <<std::endl;
}

// void se::TCPsocketFile::setDescriptorNum(int fileDescriptor)
// {
    // colseSocket();
    // m_fileDescriptor = fileDescriptor;
// }

void se::TCPsocketFile::colseSocket() const
{
    close(m_fileDescriptor);
    std::cout << "\033[1;31mSocket colsed = \033[0m"<<m_fileDescriptor<<std::endl;
}

int se::TCPsocketFile::fileDescriptorNum() const noexcept
{
    return m_fileDescriptor;
}

