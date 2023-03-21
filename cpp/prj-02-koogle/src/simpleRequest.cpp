#include "simpleRequest.hpp"

se::SimpleRequest::SimpleRequest(std::string const& word)
: m_word(word)
{}

std::vector<std::string> se::SimpleRequest::getRequest() const
{
    return std::vector<std::string>{m_word};
}
