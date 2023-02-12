#include <iterator>
#include <iostream>
#include "shiftEncryption.hpp"

namespace dt
{
std::string ShiftEncryption::transform(std::string const& input)const
{
    if( input.size() == 0 ){
        return input;
    }

    std::string new_string;
    std::string::const_iterator it = input.begin();

    while(it != input.end()){
        if((*it)>='A'  && (*it)<='Z'){
            new_string.push_back(((((*it)-'A')+m_shift+26)%26)+'A');
        }else if((*it)>='a'  &&  (*it)<='z'){
            new_string.push_back(((((*it)-'a')+m_shift+26)%26)+'a');
        }else{
            new_string.push_back(*it);
        }
        ++it;
    }
    return new_string;
};

}//namespace dt