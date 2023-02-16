#include "expressionTree.hpp"

et::ExpressionTree::ExpressionTree()
: m_root(nullptr)
, m_size(0)
{}

et::ExpressionTree::ExpressionTree(ExpressionNode* root ,size_t size)
: m_root(root)
, m_size(size)
{}

et::ExpressionTree::~ExpressionTree()
{
    delete m_root;
}

int et::ExpressionTree::getValue() const
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

et::ExpressionNode*& et::ExpressionTree::root()
{
    return m_root;
}

et::ExpressionNode* const& et::ExpressionTree::root() const
{
    return m_root;
}