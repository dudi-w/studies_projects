#include "clientQueryHandler.hpp"
#include "tools.hpp"

se::ClientQueryHandler::ClientQueryHandler(std::string const& serverAddress, uint16_t port)
: m_TCPclient(serverAddress, port)
, m_fileDescription(nullptr)
{
}

void se::ClientQueryHandler::receivesRequest(se::Request& request, [[maybe_unused]] size_t resultCount)
{
    // if(m_fileDescription->fileDescriptorNum() <= 0){
        // int fileDescriptorNum = m_TCPclient.connectToServer();
        // m_fileDescription = std::make_unique<se::TCPsocketFile>(fileDescriptorNum);
        // m_fileDescription.setDescriptorNum(descriptorNum);
    // }

    // auto temp = std::ref<se::TCPsocketFile>();
    auto requestVector = request.getRequest();
    std::string message = convertToString(se::SmartRequest(requestVector));
    // m_TCPclient.createSocket();
    m_fileDescription = m_TCPclient.connectToServer();
    m_fileDescription->write(message);
}

se::Result se::ClientQueryHandler::returnResult()
{
    if(m_fileDescription->fileDescriptorNum() < 3){
        throw 1;//TODO excption
    }
    std::string message = m_fileDescription->read();
    // m_fileDescription = nullptr;//?
    return convertToResult(message);
}
