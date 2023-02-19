#ifndef EXPRESSION_NODE_HPP
#define EXPRESSION_NODE_HPP

#include <memory>

namespace et{//expression tree

class ExpressionNode
{
public:
    ExpressionNode() = default;
    virtual ~ExpressionNode() = default;

    virtual float getValue() const = 0;
};

}//namespace et

using P_ex =  std::unique_ptr<et::ExpressionNode>;

#endif