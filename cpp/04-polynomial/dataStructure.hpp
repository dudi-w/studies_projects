#include "../01-rational/rational.hpp"
#include <algorithm>//???
#include <memory.h>
#include <istream>

class ArrByte;

namespace ds
{

class ArrRational
{
    public:
        explicit ArrRational();
        explicit ArrRational(size_t m_size);
        explicit ArrRational(size_t m_size , const Rational* const arr);
        ArrRational(const ArrRational& other);
        ~ArrRational();
        
        ArrRational& operator=( const ArrRational& other);
        Rational& operator[](size_t i);
        const Rational& operator[](size_t i) const;

        size_t getSize() const;
        void display() const;

    private:
        size_t m_size;
        Rational* m_arr;
};

class ArrByte
{
    public:
        explicit ArrByte(size_t size);
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