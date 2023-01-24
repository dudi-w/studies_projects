#include "brainfuck.hpp"
#include <memory.h>

Brainfuck::Brainfuck(size_t size):
m_size(size),
m_OpStorage(new char[m_size])
{}

Brainfuck::~Brainfuck()
{
    if(m_OpStorage==NULL){
        delete[] m_OpStorage;
    }
}

void Brainfuck::setOperations(char* const program)
{
    m_ptrPro = program;
    memset(m_OpStorage ,0 ,m_size);
    while(*m_ptrPro!='\0')
    {
        std::cout<<*m_ptrPro;;
        char c = *m_ptrPro;
        translateEndExecute(c);
        ++m_ptrPro;
    }
    
}


void Brainfuck::NoOp() const
{
    return;
}

void Brainfuck::Right()
{
    ++m_OpStorage;
}

void Brainfuck::Left()
{
    --m_OpStorage;
}

void Brainfuck::Increment()
{
    ++(*m_OpStorage);
}

void Brainfuck::Decrement()
{
    --(*m_OpStorage);
}

void Brainfuck::Write() 
{
    (*m_OpStorage)= ++(*m_ptrPro);
}

void Brainfuck::Read() const
{
    std::cout<<(*m_OpStorage);
}

void Brainfuck::LoopBegin(char c)
{
    if(*m_OpStorage){
        return NoOp();
    }
    while(*m_ptrPro != ']')
    {
        ++m_ptrPro;
    }
    ++m_ptrPro;    
}

void Brainfuck::LoopEnd(char c)
{
    while(*m_ptrPro !='[')
    {
        --m_ptrPro;
    }
}

OpCode translate(char const* program){

    size_t i = 0;
    while(program[i]!= '\0'){
        switch(program[i]){

            case '>':
                ???[m_index + i] = OpCode::Right;
                break;

            case '<':
                ???[m_index + i] = OpCode::Left;

            case '.':
                ???[m_index + i] = OpCode::Read;

            case ',':
                ???[m_index + i] = OpCode::Write;
                break;

            case '+':
                ???[m_index + i] = OpCode::Increment;
                break;

            case '-':
                ???[m_index + i] = OpCode::Decrement;
                break;

            case '[':
                ???[m_index + i] = OpCode::LoopBegin;
                break;

            case ']':
                ???[m_index + i] = OpCode::LoopEnd;
                break;

            default:
                ???[m_index + i] = OpCode::NoOp;
                break;
        }                  
    }
}
