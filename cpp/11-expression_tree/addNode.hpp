#ifndef ADD_NODE_HPP
#define ADD_NODE_HPP

#include "operatorNode.hpp"

namespace et
{

class AddNode : public OperatorNode
{
public:
    AddNode();
    AddNode(et::ExpressionNode* const right ,et::ExpressionNode* const left);
    AddNode(AddNode const& other) = delete;
    AddNode& operator = (AddNode const& other) = delete;

    int getValue() const;
};

}// namespace et
#endif