#ifndef P_MULTI_QUERY_HANDLER
#define P_MULTI_QUERY_HANDLER

#include "searchQueryHandler.hpp"
#include "simpleQueryHandler.hpp"

namespace se{//Search Engine

class PMultiQueryHandler : public SearchQueryHandler
{
public:
    explicit PMultiQueryHandler(se::GetDB const& searchDB);
    PMultiQueryHandler(PMultiQueryHandler const& other) = default;
    PMultiQueryHandler& operator=(PMultiQueryHandler const& other) = default;
    virtual ~PMultiQueryHandler() = default;

    virtual void receivesRequest(se::Request& request, size_t resultCount) override;
    void receivesRequest(std::vector<std::string> const& requests, size_t resultCount);
    virtual std::unique_ptr<se::Result> returnResult() override;

private:

    bool checkLinkExistsInAllWrds(std::vector<std::string> const& words, std::string const& link);

private:
    se::GetDB const& m_searchDB;
    se::SimpleQueryHandler m_simpleQueryHandler;
    std::vector<std::string> m_requests;
    std::vector<std::pair<std::string, size_t>> m_result;
    std::unique_ptr<se::Result> m_ptrResult;
};

}//namespace se

#endif

#ifndef NMULTI_QUERY_HANDLER
#define NMULTI_QUERY_HANDLER

#include "searchQueryHandler.hpp"
#include "simpleQueryHandler.hpp"

namespace se{//Search Engine

class NMultiQueryHandler : public SearchQueryHandler
{
public:
    explicit NMultiQueryHandler(se::GetDB const& searchDB);
    NMultiQueryHandler(NMultiQueryHandler const& other) = default;
    NMultiQueryHandler& operator=(NMultiQueryHandler const& other) = default;
    virtual ~NMultiQueryHandler() = default;

    virtual void receivesRequest(se::Request& request, size_t resultCount) override;
    void receivesRequest(std::vector<std::string> const& requests, size_t resultCount);
    virtual std::unique_ptr<se::Result> returnResult() override;

private:

    bool checkLinkExistsInAllWrds(std::vector<std::string> const& words, std::string const& link);

private:
    se::GetDB const& m_searchDB;
    se::SimpleQueryHandler m_simpleQueryHandler;
    std::vector<std::string> m_requests;
    std::vector<std::pair<std::string, size_t>> m_result;
    std::unique_ptr<se::Result> m_ptrResult;
};

}//namespace se

#endif
