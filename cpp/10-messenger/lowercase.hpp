#ifndef LOWRCASE_HPP
#define LOWRCASE_HPP

#include <string>
#include "transformation.hpp"

namespace dt{

class Lowercase:public Transformation 
{
public:
    explicit Lowercase() = default;
    Lowercase(Lowercase const& other) = default;
    ~Lowercase() = default;
    Lowercase& operator=(Lowercase const& other) = default;

    std::string transform(std::string const& input)const;
};

}//namespace dt
#endif