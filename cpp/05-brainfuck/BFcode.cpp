#include "brainfuck.hpp"


bf::Code::Code(size_t size)
: m_index(0)
, m_codeMem(size)
{}

void bf::Code::operator>>(size_t i)
{
    m_index+=i;;
}

void bf::Code::operator<<(size_t i)
{
    m_index-=i;
}

size_t bf::Code::getSize() const
{
    return m_codeMem.getSize();
}

size_t bf::Code::getIndex() const
{
    return m_index;
}

bf::OpCode bf::Code::getCurrentOp() const
{   
    return static_cast <bf::OpCode> (m_codeMem[m_index]);
}

void bf::Code::setOp(bf::OpCode op)
{
    m_codeMem[m_index] = static_cast <int8_t> (op);
}

void bf::Code::jumpToEndLoop()
{
    size_t count=0;

    (*this)>>1;
    while (getCurrentOp()!= bf::OpCode::LoopEnd || count!=0)
    {
        if(getCurrentOp()==bf::OpCode::LoopBegin){
            ++count;
        }
        if(getCurrentOp()==bf::OpCode::LoopEnd){
            --count;
        }
        (*this)>>1;
    }
}

void bf::Code::jumpToHeadLoop()
{
    int count=0;

    (*this)<<1;
    while (getCurrentOp()!= bf::OpCode::LoopBegin || count!=0)
    {
        if(getCurrentOp()==bf::OpCode::LoopEnd){
            ++count;
        }
        if(getCurrentOp()==bf::OpCode::LoopBegin){
            --count;
        }
        (*this)<<1;
    }
}

void bf::Code::display()
{
    m_codeMem.display();
}

