#ifndef NUM_TOKEN_HPP
#define NUM_TOKEN_HPP

#include "../token.hpp"

namespace tk
{

class NumToken : public Token
{
public:
    explicit NumToken(size_t index ,int data ,Group group);
    NumToken(NumToken const& other) = default;
    NumToken& operator=(NumToken const& other) = default;
    ~NumToken() = default;
    
    size_t getIndex() const;
    void creatNode(std::stack<P_ex> stack) const;
    Group preyutiryGroup() const;

private:
    size_t m_index;
    int m_data;
    Group m_group;  
};

}// namespace tk

#endif