#ifndef VM_ENUM_HPP
#define VM_ENUM_HPP
#define SIZE_OPCODE 17

#include <iostream>

namespace vm 
{
enum class OpCode : int32_t
{
    Pop,
    Push,
    Add,
    Sub,
    Mul,
    Div,
    Inc,
    Dec,
    Dup,
    Swap,
    Print,
    PrintC,
    Jmp,
    Jz,
    Jnz,
    Halt,
    Nop
};

}

#endif
