#ifndef BINARY_OPERATOR_NODE_HPP
#define BINARY_OPERATOR_NODE_HPP

#include <memory>
#include "../expressionNode.hpp"

namespace et
{

class BinaryOperatorNode : public ExpressionNode
{
public:
    explicit BinaryOperatorNode(P_ex right ,P_ex left);
    BinaryOperatorNode(BinaryOperatorNode const& other) = delete;
    BinaryOperatorNode& operator=(BinaryOperatorNode const& other) = delete;
    virtual ~BinaryOperatorNode() = default;

    virtual float getValue() const = 0;

protected:
    P_ex m_right;
    P_ex m_left;
};

inline et::BinaryOperatorNode::BinaryOperatorNode(P_ex right ,P_ex left)
: m_right(std::move(right))
, m_left(std::move(left))
{}

}// namespace et

#endif
