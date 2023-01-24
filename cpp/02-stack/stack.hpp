#include <istream>
#include <iostream>
#include <ostream>
#include <assert.h> 
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
        void revDisplay() const;
        int top() const;
        std::size_t getSize() const;
        bool isEmpty() const;
        void pouring(Stack& dist);
        
    private:
        std::size_t m_capacity;
        std::size_t m_top;
        int* m_pArr;

    private:
        void realloc();
    };