#ifndef TERMINAL_OUTPUT_HPP
#define TERMINAL_OUTPUT_HPP

#include <iostream>
#include "output.hpp"

namespace dt
{
class TerminalOutput : public Output
{
public:
    explicit TerminalOutput() = default;
    TerminalOutput(TerminalOutput const& other)= default;
    TerminalOutput& operator=(TerminalOutput const& other)= default;
    ~TerminalOutput() = default;

    void returnResulte(std::string data){
        std::cout<<data<<std::endl;
    };
};

}
#endif