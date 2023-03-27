#ifndef SMART_REQUST_HPP
#define SMART_REQUST_HPP

#include "request.hpp"

namespace se{

class SmartRequest : public Request
{
public:
    explicit SmartRequest(std::string const& request);
    SmartRequest(SmartRequest const& other) = default;
    SmartRequest& operator=(SmartRequest const& other) = default;
    virtual ~SmartRequest() = default;

    virtual std::vector<std::string> const& getRequest() const override;

private:
    std::vector<std::string> m_request;
};

}

#endif
