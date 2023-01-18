#include <istream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#define STACK_SIZE 10

class Stack
{
    public:
        explicit Stack();
        explicit Stack(const Stack& other);
        Stack& operator=(const Stack& other);
        ~Stack();
        void push(int n);
        int pop();
        void display() const;
        int top() const;
        int getSize() const;
        bool isEmpty() const;
        
    private:
        std::size_t m_capacity;
        int m_top;
        int* m_pArr;

    private:
        void realloc();
    };