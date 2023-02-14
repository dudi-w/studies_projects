#ifndef SUB_NODE_HPP
#define SUB_NODE_HPP

#include "operatorNode.hpp"

namespace et
{

class SubNode : public OperatorNode
{
public:
    SubNode();
    SubNode(et::ExpressionNode* const right ,et::ExpressionNode* const left);
    SubNode(SubNode const& other) = delete;
    SubNode& operator = (SubNode const& other) = delete;

    int getValue() const;
};

}// namespace et
#endif