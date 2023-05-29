#include "clientQueryHandler.hpp"
#include "myExceptions.hpp"
#include "tools.hpp"

se::ClientQueryHandler::ClientQueryHandler(std::string const& serverAddress, uint16_t port)
: m_TCPclient(serverAddress, port)
, m_fileDescription(nullptr)
{}

void se::ClientQueryHandler::receivesRequest(se::RequestIF& request)
{
    if(m_fileDescription == nullptr){
        throw 1;//TODO
    }
    auto requestList = request.getRequest();
    std::string message = convertToString(se::Request(requestList));
    m_fileDescription = m_TCPclient.connectToServer();
    m_fileDescription->write(message);
}

se::Result se::ClientQueryHandler::returnResult()//? mybe deleted
{
    if(m_fileDescription == nullptr){
        throw 1;//TODO
    }
    
    if(int fileDescriptorNum = m_fileDescription->fileDescriptorNum(); fileDescriptorNum < 3){
        throw se::FileDiscreptorError("invalid file discreptor number " + fileDescriptorNum);
    }
    std::string message = m_fileDescription->read();//move
    m_fileDescription = nullptr;
    return convertToResult(message);
}
