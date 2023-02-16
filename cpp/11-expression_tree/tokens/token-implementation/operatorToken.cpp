#include "operatorToken.hpp"

tk::OperatorToken::OperatorToken(size_t index ,Constructor_fun constructor ,Group group)
: m_index(index)
, m_constructor(constructor)
, m_group(group)
{}

size_t tk::OperatorToken::getIndex() const
{
    return m_index;
}

void tk::OperatorToken::creatNode(std::stack<P_ex> stack) const
{
    P_ex left = std::move(stack.top());
    stack.pop();
    P_ex right = std::move(stack.top());
    stack.pop();

    P_ex root(m_constructor(std::move(right) ,std::move(left)));
    stack.push(std::move(root));
}

Group tk::OperatorToken::preyutiryGroup() const
{
    return m_group;
}