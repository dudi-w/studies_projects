#include "mulNode.hpp"

int et::MulNode::getValue() const
{
    return BinaryOperatorNode::m_left->getValue() * BinaryOperatorNode::m_right->getValue();
}