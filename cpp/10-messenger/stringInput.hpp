#ifndef STRING_INPUT_HPP
#define STRING_INPUT_HPP

#include <string>
#include "input.hpp"

class StringInput : public Input
{
public:
    StringInput(std::string const data);
    ~StringInput() = default;

    std::string returnAsString()const ;

private:
    std::string m_data;
};

StringInput::StringInput(std::string const data)
: m_data(data)
{}

std::string StringInput::returnAsString()const
{
    return m_data;
}

#endif