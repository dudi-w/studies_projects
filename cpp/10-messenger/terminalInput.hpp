#ifndef TERMINAL_INPUT
#define TERMINAL_INPUT

#include "input.hpp"
#include <iostream>
namespace dt
{
class TerminalInput : public Input
{
public:
    explicit TerminalInput();
    TerminalInput(TerminalInput const& other) = default;
    TerminalInput& operator=(TerminalInput const& other) = default;
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

}//namespace dt
#endif