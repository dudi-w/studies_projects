#ifndef RESULT_HPP
#define RESULT_HPP

#include "resultIF.hpp"

namespace se{

class Result : public ResultIF
{
public:
    explicit Result(std::vector<std::pair<std::string, size_t>> result);
    Result(Result const& other) = default;
    Result& operator=(Result const& other) = default;
    virtual ~Result() = default;

    virtual std::vector<std::pair<std::string, size_t>> getResult() const override;

private:
    std::vector<std::pair<std::string, size_t>> m_result;
};

}

#endif
