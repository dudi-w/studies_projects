#include <iostream>
class B;
class A{
public:
    B* m_ptrB;
    ~A(){std::cout<<"delete m_ptrB\n"; delete m_ptrB;}
};

class B{
public:
    A* m_ptrA;
    ~B(){std::cout<<"delete m_ptrA\n"; delete m_ptrA;}
};

int main(){
    A* a = new A;
    B* b = new B;
    a->m_ptrB = b;
    b->m_ptrA = a;
    delete b;
    return 0;
}