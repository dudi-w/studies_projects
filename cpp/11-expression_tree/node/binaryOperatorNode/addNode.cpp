#include "addNode.hpp"

int et::AddNode::getValue() const
{
    return BinaryOperatorNode::m_left->getValue() + BinaryOperatorNode::m_right->getValue();
}