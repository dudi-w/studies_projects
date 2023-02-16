#ifndef MUL_NODE_HPP
#define MUL_NODE_HPP

#include "../binaryOperatorNode.hpp"

namespace et
{

class MulNode : public BinaryOperatorNode
{
public:
    using BinaryOperatorNode::BinaryOperatorNode;
    MulNode& operator=(MulNode const& other) = delete;
    ~MulNode() = default;

    int getValue() const;
};


}// namespace et
#endif