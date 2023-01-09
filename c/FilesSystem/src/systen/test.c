#include <stdio.h>
#include <stdlib.h>

typedef struct A{
        int a;
        int b;
    }AA;
    
union B{
    AA c;
    double d;
};

int main() {
    AA ttt;
    union B www;
    www.d = 35695478965;    

printf("%d",ttt.a);
}