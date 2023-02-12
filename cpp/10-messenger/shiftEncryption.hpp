#ifndef SHIFT_ENCRYPTION_HPP
#define SHIFT_ENCRYPTION_HPP

#include "transformation.hpp"
#include <string>


namespace dt
{
class ShiftEncryption:public Transformation 
{

public:
    explicit ShiftEncryption(int shift):m_shift(shift){};
    ShiftEncryption(ShiftEncryption const& other) = default;
    ~ShiftEncryption()= default;
    ShiftEncryption& operator=(ShiftEncryption const& other) = default;

    std::string transform(std::string const& input)const;

public:
    int const m_shift;
};

}//namespace dt
#endif