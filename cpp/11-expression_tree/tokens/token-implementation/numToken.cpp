#include "numToken.hpp"
#include "../../node/numNode/numNode.hpp"

tk::NumToken::NumToken(size_t index ,float data ,Group group)
: m_index(index)
, m_data(data)
, m_group(group)
{}

size_t tk::NumToken::getIndex() const
{
    return m_index;
}

void tk::NumToken::creatNode(std::stack<P_ex>& stack) const
{
    P_ex P_node= std::make_unique<et::NumNode>(m_data);
    stack.push(std::move(P_node));
}

Group tk::NumToken::preyutiryGroup() const
{
    return m_group;
}
