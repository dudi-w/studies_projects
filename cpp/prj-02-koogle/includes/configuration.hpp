#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

namespace se{

struct Configuration
{
    std::vector<std::string> srcURL;
    size_t maxPages;
    bool bounded;
};

}

#endif
