#ifndef VM_ENUM_HPP
#define VM_ENUM_HPP
#define SIZE_OPCODE 19

#include <iostream>
#include <array>

namespace vm 
{

enum class Log : int8_t 
{
    Success,
    DivisionByZero,
    TooFewArguments,
    MakePush,
    MakeJump,
    MakeCall,
    Halt,
    invalid_program
};

static std::array<std::string, 8> arrLogs
    {"Success",
    "DivisionByZero",
    "TooFewArguments",
    "MakePush",
    "MakeJump",
    "MakeCall",
    "Halt",
    "invalid program"};

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
    Call,
    Ret,
    Nop
};

static std::array<std::string, 19> arrOpCodes
    {"Pop",
    "Push",
    "Add",
    "Sub",
    "Mul",
    "Div",
    "Inc",
    "Dec",
    "Dup",
    "Swap",
    "Print",
    "PrintC",
    "Jmp",
    "Jz",
    "Jnz",
    "Halt",
    "Call",
    "Ret",
    "Nop"};
}

#endif
