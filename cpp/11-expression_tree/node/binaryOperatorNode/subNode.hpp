#ifndef SUB_NODE_HPP
#define SUB_NODE_HPP

#include "../binaryOperatorNode.hpp"

namespace et
{

class SubNode : public BinaryOperatorNode
{
public:
    using BinaryOperatorNode::BinaryOperatorNode;
    SubNode& operator = (SubNode const& other) = delete;
    ~SubNode() = default;

    int getValue() const;
};

}// namespace et
#endif