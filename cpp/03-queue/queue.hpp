#include <ostream>
#include "../02-stack/stack.hpp"

class Queue
{
public:
    Queue();
    void inQueue(int n);
    int deQueue();
    bool isEmpty();
    int front();
    int back();
    int size();
    void display();

private:
    Stack m_inStack;
    Stack m_outStack;
};