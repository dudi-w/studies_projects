#include<algorithm>

#include "result.hpp"


se::Result::Result(LinkVec result)
: m_result(result)
{}

se::Result::Result(LinkVec::iterator begin, LinkVec::iterator end)
: m_result(begin, end)
{}

LinkVec se::Result::getResult() const
{
    return m_result;
}

se::Result se::Result::operator-(Result const& other) const
{
    LinkVec this_result = getResult();
    LinkVec other_result = other.getResult();

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
    LinkVec result = getResult();
    LinkVec other_result = other.getResult();

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
    LinkVec result;
    LinkVec this_result = getResult();
    LinkVec other_result = other.getResult();

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

LinkVec::iterator findLink(LinkVec::iterator first, LinkVec::iterator last, std::string const& val)
{
    while(first != last){
        if(first->first == val){
            return first;
        }
        ++first;
    }
    return last;
}