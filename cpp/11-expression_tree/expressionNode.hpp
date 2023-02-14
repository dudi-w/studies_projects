#ifndef EXPRESSION_NODE_HPP
#define EXPRESSION_NODE_HPP

namespace et
{

class ExpressionNode
{
public:
    ~ExpressionNode() = default;

    virtual int getValue() const = 0;
};

}
#endif