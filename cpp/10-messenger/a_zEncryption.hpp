#ifndef A_Z_ENCRYPTION_HPP
#define A_Z_ENCRYPTION_HPP

#include "transformation.hpp"
#include <string>


namespace dt
{
class A_Z_Encryption : public Transformation 
{
public:
    explicit A_Z_Encryption(){};
    A_Z_Encryption(A_Z_Encryption const& other) = default;
    ~A_Z_Encryption()= default;
    inline
    A_Z_Encryption& operator=(A_Z_Encryption const& other) = default;

    std::string transform(std::string const& input)const;
};

}//namespace dt
#endif