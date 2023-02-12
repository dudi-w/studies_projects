#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <string>

namespace dt
{
class Output
{
public:
    virtual ~Output() = default;

    virtual void returnResulte(std::string data) =0;
};

}
#endif