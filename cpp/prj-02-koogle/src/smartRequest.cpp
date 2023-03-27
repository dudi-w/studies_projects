#include "smartRequest.hpp"
#include <sstream>

se::SmartRequest::SmartRequest(std::string const& request)
{
    std::string tmp;
    std::stringstream ss(request);
    while(ss >> tmp){
        m_request.push_back(tmp);
    }
}


std::vector<std::string> const& se::SmartRequest::getRequest() const
{
    return m_request;
}
