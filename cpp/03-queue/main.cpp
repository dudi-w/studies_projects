#include "queue.hpp"

int main(int argc, char const *argv[])
{
    Queue queue1;
    for(int i(0);i<10;++i){
        queue1.inQueue(i);
        std::cout << queue1.back() <<std::endl;
    }
    queue1.display();
    queue1.deQueue();
    for(int i(30);i<36;++i){
        queue1.inQueue(i*7);
        std::cout << queue1.back() <<std::endl;
    }
    queue1.display();
    queue1.revDisplay();
    Queue queue2(queue1);
    for(int i(0);i<150;++i){
        std::cout << queue1.front() <<std::endl;
        queue1.deQueue();
    }
    queue1.deQueue();
    queue2.display();
    return 0;
}
