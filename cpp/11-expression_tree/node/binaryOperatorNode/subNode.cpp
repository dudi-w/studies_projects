#include "subNode.hpp"

int et::SubNode::getValue() const
{
    return BinaryOperatorNode::m_left->getValue() - BinaryOperatorNode::m_right->getValue();
}