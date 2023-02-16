#include "subNode.hpp"

int et::SubNode::getValue() const
{
    int leftValue = m_left->getValue();
    int rightValue = m_right->getValue();
    return leftValue - rightValue;
}