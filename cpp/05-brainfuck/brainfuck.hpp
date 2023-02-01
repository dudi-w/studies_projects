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

    Brainfuck(Brainfuck const& other) = default;
    Brainfuck& operator=(Brainfuck const& other) = default;
    ~Brainfuck() = default;

    bf::Log run( bf::Code& code);

private:
    bf::Log execute(bf::OpCode const code);

private:
    bf::Memory m_runMem;
};

bf::Code compiler(const char* const program);

}
#endif