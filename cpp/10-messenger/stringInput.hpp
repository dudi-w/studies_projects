#ifndef STRING_INPUT_HPP
#define STRING_INPUT_HPP

#include <string>
#include "input.hpp"

namespace dt
{
class StringInput : public Input
{
public:
    explicit StringInput(std::string const data): m_data(data){}
    ~StringInput() = default;

    std::string returnAsString()const{return m_data;}

private:
    std::string m_data;
};
    
} // namespace dt

#endif