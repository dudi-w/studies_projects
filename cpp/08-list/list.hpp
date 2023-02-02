#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>

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

    bool isEmpty();

    void insertFront(const T& data);
    T extractFront();
    void insertBack(const T& data);
    T extractBack();
    std::ostream& display(std::ostream& os) const;
    

private:
    template <typename U>
    class Node
    {
    public:
        explicit Node(const U& data);
        explicit Node(const U& data , Node& next);
        Node(const Node& other);
        Node& operator=(const Node& other);
        ~Node();

        const U& getData() const;
        void setData(const U& otherData);
        // const Node*& next() const;
        Node*& next();

    public:
        U m_data;
        Node* m_next;
    };

    Node<T>* m_head;
    size_t m_size;
};

}//namespace ls

template<typename T>
std::ostream& operator<<(std::ostream& os ,const ls::List<T>&  list);


#include "node.inl"
#include "list.inl"

#endif