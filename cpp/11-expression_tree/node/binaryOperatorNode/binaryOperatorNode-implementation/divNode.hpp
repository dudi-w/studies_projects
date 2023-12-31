#ifndef DIV_NODE_HPP
#define DIV_NODE_HPP

#include "../binaryOperatorNode.hpp"

namespace et
{

class DivNode : public BinaryOperatorNode
{
public:
    using BinaryOperatorNode::BinaryOperatorNode;
    DivNode& operator=(DivNode const& other) = delete;
    ~DivNode() = default;

    float getValue() const override;
};

}// namespace et

#endif
