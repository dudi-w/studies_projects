#ifndef RESULT_HPP
#define RESULT_HPP

#include <string>

namespace se{

class Result
{
public:
    explicit Result(std::vector<std::pair<std::string, size_t>> result);
    Result(Result const& other) = default;
    Result& operator=(Result const& other) = default;
    virtual ~Result() = default;

    // Result operator+(Result const& other) const;
    Result operator-(Result const& other) const;
    Result operator|(Result const& other) const;
    Result operator&(Result const& other) const;
    // Result operator^(Result const& other) const;

    virtual std::vector<std::pair<std::string, size_t>> getResult() const;
    // void sortResult();

private:
    std::vector<std::pair<std::string, size_t>> m_result;
};

}

std::vector<std::pair<std::string, size_t>>::iterator findLink(std::vector<std::pair<std::string, size_t>>::iterator first, std::vector<std::pair<std::string, size_t>>::iterator last, std::string const& val);

#endif
