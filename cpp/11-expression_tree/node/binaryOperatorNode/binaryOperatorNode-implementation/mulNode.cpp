#include "mulNode.hpp"

int et::MulNode::getValue() const
{
    int leftValue = m_left->getValue();
    int rightValue = m_right->getValue();
    return leftValue * rightValue;
}
