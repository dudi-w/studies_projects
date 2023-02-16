#ifndef EXPRESSION_NODE_HPP
#define EXPRESSION_NODE_HPP

namespace et{//expression tree

class ExpressionNode
{
public:
    ExpressionNode() = default;
    virtual ~ExpressionNode() = default;

    virtual int getValue() const = 0;
};

}//namespace et
#endif