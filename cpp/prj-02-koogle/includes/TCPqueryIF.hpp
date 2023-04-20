#ifndef TCP_QUERY_IF_HPP
#define TCP_QUERY_IF_HPP

// #include <iostream>
// #include <memory>
// #include <regex>

#include "QueryUI.hpp"
#include "TCPserver.hpp"
#include "TCPsocketFile.hpp"

namespace se{//Search Engin

class TCPquerysIF : public QuerysIF
{
public:
    explicit TCPquerysIF(uint16_t port = -1);
    TCPquerysIF(TCPquerysIF const& other) = default;
    TCPquerysIF& operator=(TCPquerysIF const& other) = default;
    ~TCPquerysIF() = default;

    virtual std::unique_ptr<se::Request> makeRequest() override;
    virtual void recieveResult(se::Result& result) const override;

private:
    se::TCPserver m_server;
    std::unique_ptr<se::TCPsocketFile> m_fileDescription;
};

}

#endif
