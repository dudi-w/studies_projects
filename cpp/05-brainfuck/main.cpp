#include "brainfuck.hpp"

int main(){
    Brainfuck first(3000);
    char* p = (char *)"+++++++>[>++++<-]>.";
    first.setOperations(p);
    return 0;
}