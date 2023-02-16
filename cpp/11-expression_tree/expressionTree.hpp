#ifndef EXPRESSION_TREE_HPP
#define EXPRESSION_TREE_HPP

#include <cstdlib>
#include "node/expressionNode.hpp"

namespace et
{

class ExpressionTree
{
public:
    explicit ExpressionTree();
    explicit ExpressionTree(ExpressionNode* root ,size_t size);
    explicit ExpressionTree(ExpressionTree const& other) = delete;
    ExpressionTree& operator=(ExpressionTree const& other) = delete;
    ~ExpressionTree();

    int getValue() const;
    size_t& size();
    size_t const& setSize() const;
    ExpressionNode*& root();
    ExpressionNode* const& root() const;

private:
    ExpressionNode* m_root;
    size_t m_size;
};

}
#endif