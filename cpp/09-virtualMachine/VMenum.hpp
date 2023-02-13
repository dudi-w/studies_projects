#ifndef VM_ENUM_HPP
#define VM_ENUM_HPP
#define SIZE_OPCODE 19

#include <iostream>
#include <array>

namespace vm 
{

enum class Log : int8_t 
{
    Start,
    Success,
    DivisionByZero,
    TooFewArguments,
    MakePush,
    MakeJump,
    MakeCall,
    Halt,
    Invalid_program,
    Empty_stack,
    Out_of_renge
};

static std::array<std::string, 11> arrLogs
    {"Start running",
    "Success",
    "Division By Zero",
    "Too Few Arguments",
    "Make Push",
    "Make Jump",
    "Make Call",
    "Halt",
    "Invalid program",
    "The stack is empty",
    "Out of renge"};

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
