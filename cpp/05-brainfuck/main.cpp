#include "brainfuck.hpp"
#include "../04-polynomial/dataStructure.hpp"

int main(){
    ds::ArrInt8 a1(5);
    a1[0]=5;
    a1[4]=3;
    ds::ArrInt8 a2(5);
    a2[0]=5;
    a2[4]=3;
    a2.printArr();
    ds::ArrInt8 c1(10);
    (a1+a2).printArr();
    //c1.printArr();
    Brainfuck first(3000);
    char* p = (char *)"+++++++>[>++++<-]>.";
    first.setOperations(p);
    first.setOperations(p);
    return 0;
}