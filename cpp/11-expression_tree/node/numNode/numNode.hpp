#ifndef NUM_NODE_HPP
#define NUM_NODE_HPP

#include "../expressionNode.hpp"

namespace et
{

class NumNode : public ExpressionNode
{
public:
    explicit NumNode(float data);
    NumNode(NumNode const& other);
    NumNode& operator=(NumNode const& other);
    ~NumNode() = default;

    float getValue() const override;

private:
    float m_data;
};

}
#endif
