#ifndef OPERATOR_TOKEN_HPP
#define OPERATOR_TOKEN_HPP

#include "../token.hpp"

namespace tk{

class OperatorToken : public Token
{
public:
    explicit OperatorToken(size_t index ,Constructor_fun constructor ,Group group);
    OperatorToken(OperatorToken const& other) = default;
    OperatorToken& operator=(OperatorToken const& other) = default;
    ~OperatorToken() = default;

    size_t getIndex() const override;
    void creatNode(std::stack<P_ex>& stack) const override;
    Group preyutiryGroup() const override ;

private:
    size_t m_index;
    Constructor_fun m_constructor;
    Group m_group;
    
};

}//namespace tk

#endif