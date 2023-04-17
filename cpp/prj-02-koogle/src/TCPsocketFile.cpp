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
    // m_buffer.resize(m_buffSize, 0);
    // ipAddress.resize((strlen(ipAddress.data())));//TODO
}

se::TCPsocketFile::~TCPsocketFile()
{
    colseSocket();
}

std::string se::TCPsocketFile::read()
{
    m_buffer.resize(0,0);
    std::cout<<m_buffer<<m_buffer.size()<< std::endl;

    while(true){
        std::string buffer(m_buffSize,0);
        int bytesReceived = recv(m_fileDescriptor, buffer.data(), m_buffSize ,0);
        if(bytesReceived <= 0){
            break;//TODO thrwo exception
        }
        m_buffer.append(buffer ,0 ,bytesReceived);
        std::cout<<"bytesReceived = "<<bytesReceived<<m_buffer<<m_buffer.size()<< std::endl;
        if(bytesReceived < m_buffSize) {
            break;
        }
    }
    return m_buffer;
}

void se::TCPsocketFile::write(std::string const& text)
{
    if(ssize_t bytesSent = send(m_fileDescriptor, text.c_str(), text.size(), 0); bytesSent < 0){
        //TODO throw
    }  
}


se::SmartRequest se::TCPsocketFile::returnAsRequest() const
{
    std::stringstream strs(m_buffer);
    std::cout<<"returnAsRequest  "<<m_buffer<<std::endl;
    std::vector<std::string> query;
    nlohmann::json j;
    strs >> j;
    from_json(j, query);
    return se::SmartRequest(query);
}

se::Result se::TCPsocketFile::returnAsResult() const
{
    std::stringstream strs(m_buffer);
    linkVec result;
    nlohmann::json j;
    strs >> j;
    from_json(j, result);
    return se::Result(result);
}

void se::TCPsocketFile::insertAsString(se::Result const& result)
{
    nlohmann::json data;
    data["result"] = result.getResult();
    m_buffer = data.dump();
}

void se::TCPsocketFile::insertAsString(se::SmartRequest const& request)
{
    nlohmann::json data;
    data["request"] = request.getRequest();
    m_buffer = data.dump();
    std::cout<<m_buffer<<std::endl;
    write(m_buffer);
}

void se::TCPsocketFile::colseSocket() const
{
    close(m_fileDescriptor);
    std::cout << "Socket colsed"<<std::endl;
}
