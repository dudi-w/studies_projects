#ifndef SIMPLE_REQUST_HPP
#define SIMPLE_REQUST_HPP

#include "request.hpp"

namespace se{

class SimpleRequest : public Request
{
public:
    explicit SimpleRequest(std::string const& word);
    SimpleRequest(SimpleRequest const& other) = default;
    SimpleRequest& operator=(SimpleRequest const& other) = default;
    virtual ~SimpleRequest() = default;

    virtual std::vector<std::string> getRequest() const override;

private:
    std::string m_word;
};

}

#endif
