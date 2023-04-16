#include "simpleRequest.hpp"
#include "wordParser.hpp"
#include "tools.hpp"

se::SimpleRequest::SimpleRequest(std::string const& request)
{
    std::string new_request = request;
    makeLowercase(new_request);

    std::istringstream iss(new_request);
    std::string word;
    while (iss >> word){
        m_request.push_back(word);
    }

}

std::vector<std::string> const& se::SimpleRequest::getRequest() const
{
    return m_request;
}
