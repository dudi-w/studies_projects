#include "addNode.hpp"

et::AddNode::AddNode()
{
    OperatorNode::right() = nullptr;
    OperatorNode::left() = nullptr;
}

et::AddNode::AddNode(et::ExpressionNode* const right ,et::ExpressionNode* const left)
{
    OperatorNode::right() = right;
    OperatorNode::left() = left;
}

int et::AddNode::getValue() const
{
    return (*OperatorNode::left()).getValue() + (*OperatorNode::right()).getValue();
}