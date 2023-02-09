#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP
#include <string>


namespace dt{

class Transformation
{

public:

    virtual ~Transformation() = default;

    virtual std::string transform(std::string const& input)const = 0;

};


}//namespace dt
#endif