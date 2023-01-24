#include "stack.hpp"

int main(){
    Stack stack1;
    for(int i(0); i<5;++i){
        stack1.push(i);
    }
    stack1.display();
    std::cout << "\033[3;35m" << std::endl;
    stack1.revDisplay();
    std::cout << "\033[3;33m" << std::endl;
    Stack stack2(stack1);
    stack2.display();
    std::cout << "\033[3;34m" << std::endl;
    stack2.pouring(stack1);
    stack1.display();
    for(int i(0); i<120;++i){
        std::cout << stack1.pop() << std::endl;
    }
    return 0;
}