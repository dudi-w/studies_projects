#ifndef EXPRESSION_TREE_HPP
#define EXPRESSION_TREE_HPP

#include <memory>

#include "../node/expressionNode.hpp"

namespace et{

class ExpressionTree
{
public:
    explicit ExpressionTree();
    explicit ExpressionTree(std::unique_ptr<ExpressionNode> root ,size_t size);
    explicit ExpressionTree(ExpressionTree const& other) = delete;
    ExpressionTree& operator=(ExpressionTree const& other) = delete;
    ~ExpressionTree() = default;

    float getValue() const;
    size_t& size();
    size_t const& setSize() const;

private:
    std::unique_ptr<ExpressionNode> m_root;
    size_t m_size;
};

}
#endif
