#ifndef RESULT_HPP
#define RESULT_HPP

#include <string>


namespace se{
    
using LinkVec = std::vector<std::pair<std::string, float>>;

class Result
{
public:
    explicit Result(se::LinkVec result);
    explicit Result(se::LinkVec::iterator begin, se::LinkVec::iterator end);
    Result(Result const& other) = default;
    Result& operator=(Result const& other) = default;
    Result& operator=(Result && other) = default;
    virtual ~Result() = default;

    Result operator-(Result const& other) const;
    Result operator|(Result const& other) const;
    Result operator&(Result const& other) const;

    virtual se::LinkVec getResult() const;

private:
    se::LinkVec m_result;
};

}

#endif
