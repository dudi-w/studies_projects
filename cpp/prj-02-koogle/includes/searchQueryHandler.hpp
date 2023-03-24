#ifndef SEARCH_QUERY_HANDLER
#define SEARCH_QUERY_HANDLER

#include <algorithm>
#include <memory>

#include "searchDatabase.hpp"
#include "request.hpp"
#include "resultIF.hpp"

namespace se{//Search Engine

class SearchQueryHandler
{
public:
    virtual ~SearchQueryHandler() = default;

    virtual void receivesRequest(se::Request& request) = 0;
    virtual std::unique_ptr<se::ResultIF> returnResult() = 0;
};

}//namespace se

#endif
