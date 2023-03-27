#include<algorithm>

#include "result.hpp"

se::Result::Result(std::vector<std::pair<std::string, size_t>> result)
: m_result(result)
{}

std::vector<std::pair<std::string, size_t>> se::Result::getResult() const
{
    return m_result;
}

// se::Result se::Result::operator+(Result const& other) const
// {

// }

se::Result se::Result::operator-(Result const& other) const
{
    std::vector<std::pair<std::string, size_t>> this_result = getResult();
    std::vector<std::pair<std::string, size_t>> other_result = other.getResult();

    auto it = other_result.begin();
    while(it != other_result.end()){
        auto find = findLink(this_result.begin() ,this_result.end(), it->first);
        if(find != this_result.end()){
            this_result.erase(find);
        }
        ++it;
    }
    return se::Result(this_result);
}

se::Result se::Result::operator|(Result const& other) const
{
    std::vector<std::pair<std::string, size_t>> result = getResult();
    std::vector<std::pair<std::string, size_t>> other_result = other.getResult();

    auto it = other_result.begin();
    while(it != other_result.end()){
        auto find = findLink(result.begin() ,result.end(), it->first);
        if(find == result.end()){
            result.push_back(*it);
        }else{
            find->second = std::min(find->second ,it->second );
        }
        ++it;
    }
    return se::Result(result);
}

se::Result se::Result::operator&(Result const& other) const
{
    std::vector<std::pair<std::string, size_t>> result;
    std::vector<std::pair<std::string, size_t>> this_result = getResult();
    std::vector<std::pair<std::string, size_t>> other_result = other.getResult();

    auto it = other_result.begin();
    while(it != other_result.end()){
        auto find = findLink(this_result.begin() ,this_result.end(), it->first);
        if(find != this_result.end()){
            result.push_back(std::pair(find->first, std::min(find->second ,it->second)));
        }
        ++it;
    }
    return se::Result(result);
}

// se::Result se::Result::operator^(Result const& other) const
// {

// }

std::vector<std::pair<std::string, size_t>>::iterator findLink(std::vector<std::pair<std::string, size_t>>::iterator first, std::vector<std::pair<std::string, size_t>>::iterator last, std::string const& val)
{
    while(first != last){
        if(first->first == val){
            return first;
        }
        ++first;
    }
    return last;
}