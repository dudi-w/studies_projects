#ifndef BF_MEM_HPP
#define BF_MEM_HPP

#include "dataStructure.hpp"

namespace bf
{
class Memory
{
    public:
        explicit Memory(size_t size);

        // int8_t& operator[](size_t i);
        // const int8_t& operator[](size_t i) const;
        void operator>>(size_t i);
        void operator<<(size_t i);
        void operator++();
        void operator--();
        void operator++(int);
        void operator--(int);
        
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