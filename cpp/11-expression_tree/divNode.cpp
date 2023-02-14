#include "divNode.hpp"

et::DivNode::DivNode()
{
    OperatorNode::right() = nullptr;
    OperatorNode::left() = nullptr;
}

et::DivNode::DivNode(et::ExpressionNode* const right ,et::ExpressionNode* const left)
{
    OperatorNode::right() = right;
    OperatorNode::left() = left;
}

int et::DivNode::getValue() const
{
    return (*OperatorNode::left()).getValue() / (*OperatorNode::right()).getValue();
}