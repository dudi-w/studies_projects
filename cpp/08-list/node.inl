#include "node.hpp"

template<typename U>
ls::Node<U>::Node(const U& data)
: m_data(data)
, m_next(nullptr)
{}

template<typename U>
ls::Node<U>::Node(const U& data , const U& next)
: m_data(data)
, m_next(next)
{}

template<typename U>
ls::Node<U>::Node(const Node& other)
: m_data(other.data)
, m_next(nullptr)
{}

template<typename U>
ls::Node<U>& ls::Node<U>::operator=(const Node& other)
{   
    if(this==&other){
        return (*this)
    }

    m_data = other.m_data; //whet about cpye the pointer??
    return (*this);
}

template<typename U>
ls::Node<U>::~Node()
{
    std::cout<<"delete\n";
    if(m_next!=nullptr){
        delete m_next;
    }
}

template<typename U>
const U& ls::Node<U>::getData() const
{
    return m_data;
}

template<typename U>
void ls::Node<U>::setData(const U& otherData)
{
    m_data = otherData;
}

template<typename U>
const ls::Node<U>*& ls::Node<U>::next() const
{
    return m_next;
}

template<typename U>
ls::Node<U>*& ls::Node<U>::next()
{
    return m_next;
}