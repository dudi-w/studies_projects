#ifndef VM_ENUM_HPP
#define VM_ENUM_HPP

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
