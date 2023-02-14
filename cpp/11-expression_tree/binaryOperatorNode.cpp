#include "binaryOperatorNode.hpp"

et::BinaryOperatorNode::~BinaryOperatorNode()
{
    delete m_left; delete m_right;
}

et::ExpressionNode* const& et::BinaryOperatorNode::right() const
{
    return m_right;
}

et::ExpressionNode* const& et::BinaryOperatorNode::left() const
{
    return m_left;
}

et::ExpressionNode*& et::BinaryOperatorNode::right()
{
    return m_right;
}

et::ExpressionNode*& et::BinaryOperatorNode::left()
{
    return m_left;
}