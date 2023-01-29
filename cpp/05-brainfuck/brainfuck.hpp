#ifndef BREINFUCK_HPP
#define BREINFUCK_HPP

#include <cstdlib>
#include "BFenum.hpp"
#include "BFcode.hpp"
#include "BFmemory.hpp"

namespace bf
{

class Brainfuck
{
public:
    explicit Brainfuck(size_t size);

    bf::Log compiler(const char* const program);
    bf::Log run();

private:
    size_t checkValid(const char* const program);
    bf::Log translate(const char* const program);
    void execute(bf::OpCode const code);

private:
    bf::Code m_codeStor;
    bf::Memory m_runMem;
};
}

#endif