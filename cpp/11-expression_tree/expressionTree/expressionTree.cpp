#include "expressionTree.hpp"

et::ExpressionTree::ExpressionTree()
: m_root(nullptr)
, m_size(0)
{}

et::ExpressionTree::ExpressionTree(std::unique_ptr<ExpressionNode> root ,size_t size)
: m_root(std::move(root))
, m_size(size)
{}

float et::ExpressionTree::getValue() const
{
    return m_root->getValue();
}

size_t& et::ExpressionTree::size()
{
    return m_size;
}

size_t const& et::ExpressionTree::setSize() const
{
    return m_size;
}
