#include "shiftEncryption.hpp"
#include <iterator>
#include <iostream>

namespace dt{

std::string ShiftEncryption::transform(std::string const& input)const
{
    if( input.size() == 0 ){
        return input;
    }

    std::string new_string;
    std::string::const_iterator it = input.begin();

    while(it != input.end()){
        if((*it)<=90 && (*it)>=65){
            new_string.push_back(((((*it)-65)+m_shift)%26)+65);
        }else if((*it)<=122 && (*it)>=97){
            new_string.push_back(((((*it)-97)+m_shift)%26)+97);
        }else{
            new_string.push_back(*it);
        }
        ++it;
    }
    
    return new_string;
    
};

}//namespace dt