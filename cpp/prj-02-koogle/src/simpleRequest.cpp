#include "simpleRequest.hpp"
#include <iostream>

se::SimpleRequest::SimpleRequest(std::string const& request)
: m_word(request)
{}

std::string const& se::SimpleRequest::getRequest() const
{
    return m_word;
}
