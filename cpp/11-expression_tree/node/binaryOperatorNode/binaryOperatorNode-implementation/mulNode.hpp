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

    float getValue() const override;
};

}// namespace et

#endif
