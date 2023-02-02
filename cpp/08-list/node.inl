#include "list.hpp"


template<typename T>
template<typename U>
ls::List<T>::Node<U>::Node(const U& data)
: m_data(data)
, m_next(nullptr)
{}

template<typename T>
template<typename U>
ls::List<T>::Node<U>::Node(const U& data , List<T>::Node<U>& next)
: m_data(data)
, m_next(&next)
{}

template<typename T>
template<typename U>
ls::List<T>::Node<U>::Node(const Node& other)
: m_data(other.m_data)
, m_next(nullptr)
{}

template<typename T>
template<typename U>
ls::List<T>::Node<U>& ls::List<T>::Node<U>::operator=(const Node& other)
{   
    if(this==&other){
        return (*this);
    }

    m_data = other.m_data; //whet about cpye the pointer??
    return (*this);
}

template<typename T>
template<typename U>
ls::List<T>::Node<U>::~Node()
{
    delete m_next;
}

template<typename T>
template<typename U>
const U& ls::List<T>::Node<U>::getData() const
{
    return m_data;
}

template<typename T>
template<typename U>
void ls::List<T>::Node<U>::setData(const U& otherData)
{
    m_data = otherData;
}

// template<typename T>
// template<typename U>
// const ls::List<T>::Node<U>* & ls::List<T>::Node<U>::next() const
// {
//     return m_next;
// }

template<typename T>
template<typename U>
ls::List<T>::Node<U>* & ls::List<T>::Node<U>::next()
{
    return m_next;
}