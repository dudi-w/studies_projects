#ifndef OPERATOR_NODE_HPP
#define OPERATOR_NODE_HPP

#include "expressionNode.hpp"

namespace et
{

class OperatorNode : public ExpressionNode
{
public:
    ~OperatorNode() {delete m_left; delete m_right;}

    et::ExpressionNode* const& right() const {return m_right;}
    et::ExpressionNode* const& left() const {return m_left;}
    et::ExpressionNode*& right() {return m_right;}
    et::ExpressionNode*& left() {return m_left;}
    virtual int getValue() const = 0;

private:
    ExpressionNode* m_right;
    ExpressionNode* m_left;
};

}// namespace et
#endif