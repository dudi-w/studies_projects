#include "addNode.hpp"

float et::AddNode::getValue() const
{
    float leftValue = m_left->getValue();
    float rightValue = m_right->getValue();
    return leftValue + rightValue;
}
