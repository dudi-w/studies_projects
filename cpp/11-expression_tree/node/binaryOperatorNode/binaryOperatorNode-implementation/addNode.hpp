#ifndef ADD_NODE_HPP
#define ADD_NODE_HPP

#include "../binaryOperatorNode.hpp"

namespace et
{

class AddNode : public BinaryOperatorNode
{
public:
    using BinaryOperatorNode::BinaryOperatorNode;
    AddNode& operator=(AddNode const& other) = delete;
    ~AddNode() = default;
    
    int getValue() const override;
};

}// namespace et
#endif
