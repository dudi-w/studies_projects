#include <algorithm>

#include "result.hpp"

se::Result::Result(LinkVec result)
: m_result(result)
{}

se::Result::Result(LinkVec::iterator begin, LinkVec::iterator end)
: m_result(begin, end)
{}

se::LinkVec se::Result::getResult() const
{
    return m_result;
}

se::Result se::Result::operator-(Result const& other) const
{
    LinkVec this_result = getResult();
    LinkVec other_result = other.getResult();
    auto it = other_result.begin();
    while(it != other_result.end()){
        auto find = std::find_if(this_result.cbegin() ,this_result.cend(),[it](std::pair<std::string, float> const& pair){return pair.second == it->second;});
        if(find != this_result.cend()){
            it = this_result.erase(find);
        }else{
            ++it;
        }
    }
    return se::Result(this_result);
}

se::Result se::Result::operator|(Result const& other) const
{
    LinkVec result = getResult();
    LinkVec other_result = other.getResult();

    auto it = other_result.begin();
    while(it != other_result.cend()){
        auto res = std::find_if(result.begin() ,result.end(), [it](std::pair<std::string, float>const& pair){return pair.second == it->second;});
        if(res == result.cend()){
            result.push_back(*it);
        }else{
            res->second = std::min(res->second ,it->second );
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

    auto it = other_result.cbegin();
    while(it != other_result.cend()){
        auto find = std::find_if(this_result.cbegin() ,this_result.cend(), [it](std::pair<std::string, float>const& pair){return pair.second == it->second;});
        if(find != this_result.cend()){
            result.push_back(std::pair(find->first, std::min(find->second ,it->second)));
        }
        ++it;
    }
    return se::Result(result);
}
