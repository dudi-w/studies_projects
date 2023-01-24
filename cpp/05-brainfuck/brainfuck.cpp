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

void Brainfuck::translateEndExecute(char const c){

    switch(c)
    {
    case '>':
        return Right();
    
    case '<':
        return Left();

    case '.':
        return Read();

    case ',':
        return Write();

    case '+':
        return Increment();

    case '-':
        return Decrement();

    case '[':
        return LoopBegin( c);
    
    case ']':
        return LoopEnd(c);

    default:
        return NoOp();;
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
