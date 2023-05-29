#ifndef TCP_QUERY_HPP
#define TCP_QUERY_HPP

#include "queryBuilderIF.hpp"
#include "TCPserver.hpp"
#include "TCPsocketFile.hpp"

namespace se{//Search Engin

class TCPquerys : public QueryBuilder
{
public:
    explicit TCPquerys(uint16_t port = -1);
    TCPquerys(TCPquerys const& other) = default;
    TCPquerys& operator=(TCPquerys const& other) = default;
    ~TCPquerys() = default;

    virtual std::unique_ptr<se::RequestIF> makeRequest() override;
    virtual void recieveResult(se::Result& result) const override;

private:
    se::TCPserver m_server;
    std::unique_ptr<se::TCPsocketFile> m_fileDescription;
};

}

#endif