#ifndef NUM_NODE_HPP
#define NUM_NODE_HPP

#include "expressionNode.hpp"

namespace et
{

class NumNode : public ExpressionNode
{
public:
    explicit NumNode(int data);
    NumNode(NumNode const& other);
    NumNode& operator=(NumNode const& other);
    ~NumNode() = default;

    int getValue() const;

private:
    int m_data;
};

}
#endif