#ifndef VM_ENUM_HPP
#define VM_ENUM_HPP

#include <iostream>

namespace vm 
{
    

union VMdata
{
    int32_t data;
    enum class OpCode: int32_t{
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
        Dec
    } code;
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
