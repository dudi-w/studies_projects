#include "addNode.hpp"

int et::AddNode::getValue() const
{
    int leftValue = m_left->getValue();
    int rightValue = m_right->getValue();
    return leftValue + rightValue;
}