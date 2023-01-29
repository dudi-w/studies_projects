#ifndef DADESTRUCTURE_HPP
#define DADESTRUCTURE_HPP

#include <cstdlib>

namespace ds
{

class ArrByte
{
    public:
        explicit ArrByte();
        explicit ArrByte(size_t  size);
        ArrByte(const ArrByte& other);
        ~ArrByte();

        ArrByte& operator=( const ArrByte& other);
        ArrByte operator+( const ArrByte& other) const;
        ArrByte& operator+=( const ArrByte& other);
        int8_t& operator[](size_t i);
        const int8_t& operator[](size_t i) const;

        void cleanMamory() const;
        void display() const;
        size_t getSize() const;

    public:
        size_t m_size;
        int8_t* m_arr;
};
}
#endif