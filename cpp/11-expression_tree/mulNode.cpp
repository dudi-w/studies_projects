#include "mulNode.hpp"

et::MulNode::MulNode()
{
    OperatorNode::right() = nullptr;
    OperatorNode::left() = nullptr;
}
et::MulNode::MulNode(et::ExpressionNode* const right ,et::ExpressionNode* const left)
{
    OperatorNode::right() = right;
    OperatorNode::left() = left;
}

int et::MulNode::getValue() const
{
    return (*OperatorNode::left()).getValue() * (*OperatorNode::right()).getValue();
}