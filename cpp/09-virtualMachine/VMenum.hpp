#ifndef VM_ENUM_HPP
#define VM_ENUM_HPP

#include <iostream>

namespace vm 
{
enum class OpCode : int32_t
{
    Add,
    Sub,
    Mul,
    Div,
    Pop,
    Push,
    Dup,
    Swap,
    Print,
    PrintC,
    Nop,
    Halt,
    Inc,
    Dec,
    Jmp,
    Jz,
    Jnz
};

// enum class Log
// {
//     success,
//     out_of_memory,
//     inValidProgram,
//     gumpEnd,
//     gumpHead
// };
}

#endif
