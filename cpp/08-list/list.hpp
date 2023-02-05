#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>

namespace ls
{
// template <typename T>
// class list<T>::Node<T>;

template <typename T>
class List
{
    template <typename U> class Node;
public:
    explicit List();
    List(const List& other);
    List& operator=(const List& other);
    ~List();

    class iterator 
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        // using difference_type   = std::ptrdiff_t;
        using value_type        = Node<T>;

        explicit iterator() : m_ptr(nullptr) {}
        explicit iterator(value_type* ptr) : m_ptr(ptr) {}

        value_type& operator*() const { return *m_ptr; }
        value_type* operator->() { return m_ptr; }
        iterator operator++() { m_ptr = (*m_ptr).m_next ; return *this; }  
        iterator operator++(int) { m_ptr = m_ptr->m_next ; return *this; }
        
        friend bool operator== (const iterator& a, const iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const iterator& a, const iterator& b) { return a.m_ptr != b.m_ptr; };  

    private:
        value_type* m_ptr;
    };

    bool isEmpty();

    iterator begin();
    iterator end();

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