#ifndef REQUST_HPP
#define REQUST_HPP

#include <string>
#include <vector>

namespace se{

class Request
{
public:
    virtual ~Request() = default;

    virtual std::vector<std::string> getRequest() const = 0;

};

}

#endif
