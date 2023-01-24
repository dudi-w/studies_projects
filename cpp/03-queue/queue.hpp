#include <ostream>
#include "../02-stack/stack.hpp"

class Queue
{
public:
    Queue();
    void inQueue(int n);
    int deQueue();
    bool isEmpty() const;
    int front();
    int back();
    std::size_t getSize() const;
    void display() const;
    void revDisplay() const;

private:
    Stack m_inStack;
    Stack m_outStack;
};