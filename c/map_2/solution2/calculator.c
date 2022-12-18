#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "solution2.h"

bool checkCompatibility(char const *argv, struct StackList **stackNum , struct StackList **stackOper){
    int len =strlen(argv);
    
    if((len)%2==0)
        return false;
    for(int i=0; i<((len/2)+1) ; ++i){
        if(argv[i]>57 || argv[i]< 48)
            return false;
        else
            push2(stackNum ,argv[i]-48 );
    }
    for(int i=len-1 ;i>len/2;--i){
        if((argv[i])!='+' && argv[i]!='-' && argv[i]!='*' && argv[i]!='/'){
            return false;
        }
        else
            push2(stackOper,argv[i]);
    }
    return true;
}

void calculator(struct StackList **stackNum , struct StackList **stackOper){
    
    while(!isEmpty2(*stackOper)){

        switch (pop2(stackOper)){
            case '+':
                push2(stackNum, pop2(stackNum)+pop2(stackNum));
                break;

            case '-':
                int a = pop2(stackNum);
                int b = pop2(stackNum);
                push2(stackNum, b-a);
                break;

            case '*':
                push2(stackNum, pop2(stackNum)*pop2(stackNum));
                break;

            case '/':
                int c = pop2(stackNum);
                int d = pop2(stackNum);
                push2(stackNum, d/c);
                break;

            default:
                printf("ERROR");
                break;
        }
    }
    printf("The result is \x1B[31m%d\x1B[0m\n", pop2(stackNum));
}