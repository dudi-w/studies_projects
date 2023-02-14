#ifndef DIV_NODE_HPP
#define DIV_NODE_HPP

#include "operatorNode.hpp"

namespace et
{

class DivNode : public OperatorNode
{
public:
    DivNode();
    DivNode(et::ExpressionNode* const right ,et::ExpressionNode* const left);
    DivNode(DivNode const& other) = delete;
    DivNode& operator = (DivNode const& other) = delete;

    int getValue() const;
};

}// namespace et
#endif