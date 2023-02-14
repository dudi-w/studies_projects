#include "subNode.hpp"

et::SubNode::SubNode()
{
    OperatorNode::right() = nullptr;
    OperatorNode::left() = nullptr;
}
et::SubNode::SubNode(et::ExpressionNode* const right ,et::ExpressionNode* const left)
{
    OperatorNode::right() = right;
    OperatorNode::left() = left;
}

int et::SubNode::getValue() const
{
    return (*OperatorNode::left()).getValue() - (*OperatorNode::right()).getValue();
}