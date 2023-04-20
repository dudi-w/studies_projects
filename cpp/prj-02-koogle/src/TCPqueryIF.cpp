#include "TCPqueryIF.hpp"
#include "tools.hpp"

se::TCPquerysIF::TCPquerysIF(uint16_t port)
: m_server(port)
, m_fileDescription(nullptr)
{
    m_server.createSocket();
    m_server.bindSocket();
    m_server.listenForClient();
}

#include <iostream>//!
std::unique_ptr<se::Request> se::TCPquerysIF::makeRequest()
{
    std::cout<<"makeRequest"<<std::endl;
    m_fileDescription = m_server.acceptTorecieve();
    std::string message = m_fileDescription->read();
    
    auto request = convertToRequest(message);
    if(request.getRequest().at(0) == "1234"){
        return nullptr;
    }
    return std::make_unique<se::SimpleRequest>(request);
}

void se::TCPquerysIF::recieveResult(se::Result& result) const
{
    if(m_fileDescription->fileDescriptorNum() < 3){
        throw 1;//TODO
        return;
    }
    auto message = convertToString(result);
    m_fileDescription->write(message);
    
}

