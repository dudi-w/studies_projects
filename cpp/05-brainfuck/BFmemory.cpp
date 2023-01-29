#include "BFmemory.hpp"
#include <iostream>

bf::Memory::Memory(size_t size):
m_index(size/2),
m_codeMem(size)
{}

void bf::Memory::operator>>(size_t i)
{
    if(!CheckMemLeak(i)){
        realloc();
    }
    m_index+=i;
}

void bf::Memory::operator<<(size_t i)
{
    if(!CheckMemLeak(-static_cast<__int128_t>(i))){
        realloc();
    }
    m_index-=i;
}

int8_t& bf::Memory::operator++()
{
    return ++m_codeMem[m_index];
}

int8_t& bf::Memory::operator--()
{
    return --m_codeMem[m_index];
}

// void bf::Memory::operator++(int n)
// {
//     m_codeMem[m_index]+=n;
// }

// void bf::Memory::operator--(int n)
// {
//     m_codeMem[m_index]-=n;
// }

void bf::Memory::write()
{
    std::cout<<"Enter your date";
    char n;
    std::cin>>n;
    m_codeMem[m_index]= static_cast <int8_t> (n);
}

void bf::Memory::read() const
{
    std::cout<<static_cast <char> (m_codeMem[m_index])<<std::flush;
}

void bf::Memory::cleanMem()
{
    m_codeMem.cleanMamory();
    m_index = m_codeMem.getSize()/2;
}

size_t bf::Memory::getSize() const
{
    return m_codeMem.getSize();
}

size_t bf::Memory::getIndex() const
{
    return m_index;
}

int8_t bf::Memory::getValue() const
{
    return m_codeMem[m_index];
}

void bf::Memory::display() const
{
    m_codeMem.display();
}

void bf::Memory::realloc()
{
    ds::ArrByte temp(getSize()/2);
    m_codeMem = temp+m_codeMem+temp;
    m_index+= temp.getSize();
}

bool bf::Memory::CheckMemLeak(__int128_t n) const
{
    return !((m_index+n)>= m_codeMem.getSize() || (m_index+n) < 0);
}
