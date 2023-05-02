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
    if(m_fileDescription == nullptr){
        throw 1;//TODO
    }

    std::string message = m_fileDescription->read();//? why not check the file discriptor number?
    auto request = convertToRequest(message);
    if(request.getRequest().at(0) == "1234"){
        return nullptr;
    }
    return std::make_unique<se::Request>(request);
}

void se::TCPquerysIF::recieveResult(se::Result& result) const
{
    if(m_fileDescription == nullptr){
        throw 1;//TODO
    }

    if(int fileDescriptorNum = m_fileDescription->fileDescriptorNum(); fileDescriptorNum < 3){
        throw se::FileDiscreptorError("invalid file discreptor number " + fileDescriptorNum);
    }
    auto message = convertToString(result);
    m_fileDescription->write(message);
}
