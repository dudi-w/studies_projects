#ifndef EXPRESSION_NODE_HPP
#define EXPRESSION_NODE_HPP

//expression tree
namespace et
{

class ExpressionNode
{
public:
    ExpressionNode() = default;
    virtual ~ExpressionNode() = default;

    virtual int getValue() const = 0;
};

}
#endif