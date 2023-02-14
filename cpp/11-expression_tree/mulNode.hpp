#ifndef MUL_NODE_HPP
#define MUL_NODE_HPP

#include "operatorNode.hpp"

namespace et
{

class MulNode : public OperatorNode
{
public:
    MulNode();
    MulNode(et::ExpressionNode* const right ,et::ExpressionNode* const left);
    MulNode(MulNode const& other) = delete;
    MulNode& operator = (MulNode const& other) = delete;

    int getValue() const;
};


}// namespace et
#endif