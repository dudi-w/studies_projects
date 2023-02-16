#include "divNode.hpp"

int et::DivNode::getValue() const
{
    return BinaryOperatorNode::m_left->getValue() / BinaryOperatorNode::m_right->getValue();
}