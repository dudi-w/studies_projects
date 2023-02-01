#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>
#include "node.hpp"

namespace ls
{
template <typename T>
class List
{
public:
    explicit List();
    List(const List& other);
    List& operator=(const List& other);
    ~List();

    void insertFront(const T& data);
    T extractFront();
    void insertBack(const T& data);
    T extractBack();
    void display() const;

private:
    ls::Node<T>* m_head;
    size_t m_size;
};

#include "list.inl"
}
#endif