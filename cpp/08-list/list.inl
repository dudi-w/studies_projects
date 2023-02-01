#include <cassert>
#include "list.hpp"

template<typename T>
ls::List<T>::List()
: m_head(nullptr)
, m_size(0)
{}

template<typename T>
ls::List<T>::List(const List& other)
{
    if(this==&other){
        return;// *this;
    }

    Node<T>* temp = other.m_head;
    while(temp != nullptr){
        insertBack(temp->m_data);
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
    }

    ls::Node<T>* temp = other.m_head;
    while(temp != nullptr){
        insertBack(temp->m_data);
        temp = temp->m_next;
    }
}

template<typename T>
ls::List<T>::~List()
{
    delete m_head;
}

template<typename T>
void ls::List<T>::insertFront(const T& data)
{
    if(m_head == nullptr){
        m_head = new ls::Node<T>(data);
    }
    else{
        m_head = new ls::Node<T>(data, *m_head);
    }
}

template<typename T>
T ls::List<T>::extractFront()
{
    assert(m_head!=nullptr && "list empty error");
    ls::Node<T> tempNode(*m_head);
    ls::Node<T>* tempP = (m_head);
    m_head = m_head->m_next;
    if(tempP->m_next != nullptr){tempP->m_next == nullptr};
    delete tempP;
    return tempNode;
}

template<typename T>
void ls::List<T>::insertBack(const T& data)
{   
    Node<T>* temp = m_head;
    while(temp->m_next != nullptr){
        temp = temp->m_next;
    }
    temp->m_next = new ls::Node<T>(data);
}

template<typename T>
T ls::List<T>::extractBack()
{
    Node<T>* tempP1 = m_head , tempP2;
    if(m_size>=1){
        return extractFront();
    }
    while(tempP1->m_next->m_next != nullptr){
        tempP1 = temp->m_next;
    }
    tempP2 = tempP1->m_next;
    tempP1->m_next = tempP2
    ls::Node<T> tempNode(*tempP2);

    return tempNode;
}

template<typename T>
void ls::List<T>::display() const
{

}
