#include <iterator>
#include <iostream>
#include "a_zEncryption.hpp"

namespace dt{

std::string A_Z_Encryption::transform(std::string const& input)const
{
    if( input.size() == 0 ){
        return input;
    }

    std::string new_string;
    std::string::const_iterator it = input.begin();

    while(it != input.end()){
        if((*it)>='A'  && (*it)<='Z'){
            new_string.push_back(('Z')-((*it)-'A'));
        }else if((*it)>='a'  &&  (*it)<='z'){
            new_string.push_back(('z')-((*it)-'a'));
        }else{
            new_string.push_back(*it);
        }
        ++it;
    }
    
    return new_string;
};

}//namespace dt