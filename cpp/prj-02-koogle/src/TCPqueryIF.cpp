#include "TCPqueryIF.hpp"
#include "myExceptions.hpp"
#include "tools.hpp"

se::TCPquerysIF::TCPquerysIF(uint16_t port)
: m_server(port)
, m_fileDescription(nullptr)
{
    m_server.createSocket();
    m_server.bindSocket();
    m_server.listenForClient();
}

std::unique_ptr<se::RequestIF> se::TCPquerysIF::makeRequest()
{
    m_fileDescription = m_server.acceptTorecieve();
    std::string message = m_fileDescription->read();
    
    auto request = convertToRequest(message);
    if(request.getRequest().at(0) == "1234"){
        return nullptr;
    }
    return std::make_unique<se::Request>(request);
}

void se::TCPquerysIF::recieveResult(se::Result& result) const
{
    
    if(int fileDescriptorNum = m_fileDescription->fileDescriptorNum(); fileDescriptorNum < 3){
        throw se::FileDiscreptorError("invalid file discreptor number " + fileDescriptorNum);
    }
    auto message = convertToString(result);
    m_fileDescription->write(message);
    // m_fileDescription = nullptr;//? not alwaed
}

