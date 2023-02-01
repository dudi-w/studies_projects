#ifndef NODE_HPP
#define NODE_HPP

namespace ls
{
template <typename U>
class Node
{
public:
    explicit Node(const U& data);
    explicit Node(const U& data , const U& next);
    Node(const Node& other);
    Node& operator=(const Node& const);
    ~Node() = default;

    const U& getData() const;
    void setData(const U& otherData);
    const Node*& next() const;
    Node*& next();

private:
    U m_data;
    Node* m_next;
};

#include "node.inl"

}
#endif