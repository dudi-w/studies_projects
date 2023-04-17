#ifndef SOCKET_FILE_HPP
#define SOCKET_FILE_HPP

#include <string>

#include "smartRequest.hpp"
#include "result.hpp"

namespace se{

class TCPsocketFile
{
public:
    explicit TCPsocketFile(int fileDescriptor);
    TCPsocketFile(TCPsocketFile const& other) = default;
    TCPsocketFile& operator=(TCPsocketFile const& other) = default;
    ~TCPsocketFile();

public:
    std::string read();
    void write(std::string const& text);
    se::SmartRequest returnAsRequest() const;
    se::Result returnAsResult() const;
    void insertAsString(se::Result const& result);
    void insertAsString(se::SmartRequest const& request);



private:
    void colseSocket() const;

private:
    int m_fileDescriptor;
    std::string m_buffer;
    uint16_t m_buffSize;
};

}

#endif
