#ifndef BINARY_OPERATOR_NODE_HPP
#define BINARY_OPERATOR_NODE_HPP

#include <memory>
#include "expressionNode.hpp"

using P_Ex =  std::unique_ptr<et::ExpressionNode>;

namespace et
{

class BinaryOperatorNode : public ExpressionNode
{
public:
    explicit BinaryOperatorNode(P_Ex right ,P_Ex left);
    BinaryOperatorNode(BinaryOperatorNode const& other) = delete;
    BinaryOperatorNode& operator=(BinaryOperatorNode const& other) = delete;
    ~BinaryOperatorNode() = default;

    virtual int getValue() const = 0;

protected:
    P_Ex m_right;
    P_Ex m_left;
};

inline
et::BinaryOperatorNode::BinaryOperatorNode(P_Ex right ,P_Ex left)
: m_right(std::move(right))
, m_left(std::move(left))
{}

}// namespace et
#endif