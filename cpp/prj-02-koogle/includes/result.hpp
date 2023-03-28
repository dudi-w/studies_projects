#ifndef RESULT_HPP
#define RESULT_HPP

#include <string>

using linkVec = std::vector<std::pair<std::string, size_t>>;

namespace se{

class Result
{
public:
    explicit Result(linkVec result);
    explicit Result(linkVec::iterator begin, linkVec::iterator end);
    Result(Result const& other) = default;
    Result& operator=(Result const& other) = default;
    virtual ~Result() = default;

    Result operator-(Result const& other) const;
    Result operator|(Result const& other) const;
    Result operator&(Result const& other) const;

    virtual linkVec getResult() const;

private:
    linkVec m_result;
};

}

linkVec::iterator findLink(linkVec::iterator first, linkVec::iterator last, std::string const& val);

#endif
