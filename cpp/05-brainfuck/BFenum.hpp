#ifndef BF_ENUM_HPP
#define BF_ENUM_HPP

#include <iostream>

namespace bf 
{
    
enum class OpCode: int8_t
{
    EndOp,
    Right,
    Left,
    Increment,
    Decrement,
    Write,
    Read,
    LoopBegin,
    LoopEnd
};

enum class Log
{
    success,
    out_of_memory,
    inValidProgram,
    gumpEnd,
    gumpHead
};
}

// std::ostream& operator<<(std::ostream& os, bf::OpCode code)
// {
//     os<<(int)code<<std::flush;
//     return os;
// }
#endif