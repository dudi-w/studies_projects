#include "uppercase.hpp"
#include <iterator>

namespace dt{

std::string Uppercase::transform(std::string const& input)const
{
    if( input.size() == 0 ){
        return input;
    }

    std::string new_string;
    std::string::const_iterator it = input.begin();

    while(it != input.end()){
        new_string.push_back(toupper(*it));
        ++it;
    }

    return new_string;
    
};

}//namespace dt