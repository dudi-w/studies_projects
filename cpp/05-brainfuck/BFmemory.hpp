#ifndef BF_MEM_HPP
#define BF_MEM_HPP

#include "dataStructure.hpp"

namespace bf
{
class Memory
{
public:
    explicit Memory(size_t size);
    Memory(Memory const& other) = default;
    Memory& operator=(Memory const& other) = default;
    ~Memory() = default;

    
    void operator>>(size_t i);
    void operator<<(size_t i);
    int8_t& operator++();
    int8_t& operator--();

    void write();
    void read() const;
    void cleanMem();
    size_t getSize() const;
    size_t getIndex() const;
    int8_t getValue() const;
    void display() const;

private:
    void realloc();
    bool CheckMemLeak(__int128_t n) const;

private:
    size_t m_index;
    ds::ArrByte m_codeMem;
};
}
#endif