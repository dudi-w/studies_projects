#include "mulNode.hpp"

float et::MulNode::getValue() const
{
    float leftValue = m_left->getValue();
    float rightValue = m_right->getValue();
    return leftValue * rightValue;
}
