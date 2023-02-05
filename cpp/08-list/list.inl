#ifndef LIST_INL
#define LIST_INL

#include <cassert>
#include <iostream>
#include "list.hpp"

template<typename T>
ls::List<T>::List()
: m_head(nullptr)
, m_size(0)
{}

template<typename T>
ls::List<T>::List(const List& other)
: m_head(nullptr)
, m_size(0)
{
    Node<T> * temp = other.m_head;
    while(temp != nullptr){
        (*this).insertBack(temp->m_data);
        temp = temp->m_next;
    }
}

template<typename T>
ls::List<T>& ls::List<T>::operator=(const List& other)
{
    if(this == &other){
        return *this;
    }

    if(m_head != nullptr){
        delete m_head;
        m_head =nullptr;
        m_size=0;
    }

    Node<T>* temp = other.m_head;
    while(temp != nullptr){
        (*this).insertBack(temp->m_data);
        temp = temp->m_next;
    }
    return (*this);
}

template<typename T>
inline
ls::List<T>::~List()
{
    delete m_head;
}

template<typename T>
typename ls::List<T>::iterator ls::List<T>::begin()
{
    return iterator(m_head);
}

template<typename T>
typename ls::List<T>::iterator ls::List<T>::end()
{
    return iterator();
}

template<typename T>
bool ls::List<T>::isEmpty()
{
    return  m_head == nullptr  && m_size == 0 ? true : false;
}

template<typename T>
void ls::List<T>::insertFront(const T& data)
{
    m_head = new Node<T>(data, *m_head);
    ++m_size;
}

// template<typename T>
// ls::List<T>::iterator ls::List<T>::begin()
// {

// }

// template<typename T>
// std::iterator ls::List<T>::end()
// {

// }

template<typename T>
T ls::List<T>::extractFront()
{
    assert(m_head!=nullptr && "list empty error");
    Node<T> tempNode(*m_head);
    Node<T>* tempP = (m_head);
    m_head = m_head->m_next;
    --m_size;
    if(tempP->m_next != nullptr){tempP->m_next = nullptr;};
    delete tempP;
    return tempNode.m_data;
}

template<typename T>
void ls::List<T>::insertBack(const T& data)
{   
    if(isEmpty()){
        return insertFront(data);
    }
    
    Node<T>* temp = m_head;
    while(temp->m_next != nullptr){
        temp = temp->m_next;
    }
    
    temp->m_next = new ls::List<T>::Node<T>(data);

    ++m_size;
}

template<typename T>
T ls::List<T>::extractBack()
{
    if(m_size<=1){
        return extractFront();
    }

    Node<T>* tempP1 = m_head , *tempP2;
    
    while(tempP1->m_next->m_next != nullptr){
        tempP1 = tempP1->m_next;
    }
    tempP2 = tempP1->m_next;
    tempP1->m_next = nullptr;
    --m_size;
    Node<T> tempNode(*tempP2);
    delete tempP2;
    return tempNode.m_data;
}

template<typename T>
std::ostream& ls::List<T>::display(std::ostream& os) const
{
    Node<T>* temp = m_head;
    while(temp != nullptr){
        os << temp->m_data << " -> " << std::flush;
        temp = temp->m_next;
    }
    os<<"NULL\n";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os ,const ls::List<T>& list)
{
    return list.display(os);
}
#endif
