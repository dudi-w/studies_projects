#ifndef RESULT_IF_HPP
#define RESULT_IF_HPP

#include <string>
#include <vector>

namespace se
{
class ResultIF
{
public:
    virtual ~ResultIF() = default;

    virtual std::vector<std::pair<std::string, size_t>> getResult() const = 0;
};

}//namespace se

#endif
