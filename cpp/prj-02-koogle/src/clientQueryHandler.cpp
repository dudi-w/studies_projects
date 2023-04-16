#include "../includes/clientQueryHandler.hpp"

se::ClientQueryHandler::ClientQueryHandler()
: m_result({})
{}

void se::ClientQueryHandler::receivesRequest(se::Request& request, size_t resultCount)
{

}

se::Result se::ClientQueryHandler::returnResult()
{
    return m_result;
}
