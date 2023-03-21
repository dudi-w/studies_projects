#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

namespace se{

struct Configuration
{
    std::string srcURL;
    size_t maxPages;
    size_t maxDepth;
    bool bounded;
};

}

#endif
