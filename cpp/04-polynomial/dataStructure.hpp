#ifndef DADESTRUCTURE_HPP
#define DADESTRUCTURE_HPP


#include "../01-rational/rational.hpp"
#include <algorithm>//???
#include <memory.h>
#include <istream>

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

}
#endif