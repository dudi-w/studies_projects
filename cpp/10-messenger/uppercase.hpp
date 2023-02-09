#ifndef UPPERCASE_HPP
#define UPPERCASE_HPP
#include "transformation.hpp"
#include <string>


namespace dt{

class Uppercase:public Transformation 
{

public:

    explicit Uppercase() = default;
    Uppercase(Uppercase const& other) = default;
    ~Uppercase()= default;
    Uppercase& operator=(Uppercase const& other) = default;

    std::string transform(std::string const& input)const;

};

}//namespace dt
#endif