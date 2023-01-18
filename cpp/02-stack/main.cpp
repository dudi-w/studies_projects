#include "stack.hpp"

int main(){
    Stack stack1;
    for(int i(0); i<50;++i){
        stack1.push(i);
        std::cout<<&(std::cout)<<std::endl;
    }
    stack1.display();
    Stack stack2(stack1);
    stack2.display();
    return 0;
}