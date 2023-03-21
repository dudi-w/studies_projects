#include "result.hpp"

se::Result::Result(std::vector<std::pair<std::string, size_t>> result)
: m_result(result)
{}

std::vector<std::pair<std::string, size_t>> se::Result::getResult() const
{
    return m_result;
}
