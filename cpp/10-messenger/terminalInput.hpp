#ifndef TERMINAL_INPUT
#define TERMINAL_INPUT

#include "input.hpp"
#include <iostream>

class TerminalInput : public Input
{
public:
    TerminalInput();
    ~TerminalInput() = default;

    std::string returnAsString() const;

private:
    std::string m_data;
};

TerminalInput::TerminalInput()
{
    std::cout<<"enter your data"<<std::endl;
    std::cin >> m_data;
}

std::string TerminalInput::returnAsString() const
{
    return m_data;
}

#endif