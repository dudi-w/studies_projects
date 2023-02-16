#include "operatorToken.hpp"

tk::OperatorToken::OperatorToken(size_t index ,constructor_fun constructor ,Group group)
: m_index(index)
, m_constructor(constructor)
, m_group(group)
{}

size_t tk::OperatorToken::getIndex() const
{
    return m_index;
}

void tk::OperatorToken::creatNode(std::stack<P_Ex> stack) const
{
    P_Ex left = std::move(stack.top());
    stack.pop();
    P_Ex right = std::move(stack.top());
    stack.pop();

    P_Ex root(m_constructor(std::move(right) ,std::move(left)));
    stack.push(std::move(root));
}

Group tk::OperatorToken::preyutiryGroup() const
{
    return m_group;
}