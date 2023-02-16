#include "numNode.hpp"

et::NumNode::NumNode(int data)
: m_data(data)
{}

et::NumNode::NumNode(NumNode const& other)
: m_data(other.m_data)
{}

et::NumNode& et::NumNode::operator=(et::NumNode const& other)
{
    m_data = other.m_data;
    return *this;
}

int et::NumNode::getValue() const
{
    return m_data;
}