#ifndef RESULT_HPP
#define RESULT_HPP

#include <string>

using LinkVec = std::vector<std::pair<std::string, size_t>>;

namespace se{

class Result
{
public:
    explicit Result(LinkVec result);
    explicit Result(LinkVec::iterator begin, LinkVec::iterator end);
    Result(Result const& other) = default;
    Result& operator=(Result const& other) = default;
    virtual ~Result() = default;

    Result operator-(Result const& other) const;
    Result operator|(Result const& other) const;
    Result operator&(Result const& other) const;

    virtual LinkVec getResult() const;

private:
    LinkVec m_result;
};

}

LinkVec::iterator findLink(LinkVec::iterator first, LinkVec::iterator last, std::string const& val);

#endif
