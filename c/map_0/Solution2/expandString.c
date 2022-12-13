#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* expand(char a, char b );
void swap(char *a, char *b);

int main(int argc, char  *argv[]){
    char a = *(*(argv+1));
    char b = *(*(argv+1)+2);
    if(a>b)
        swap(&a,&b);
    char *str = expand(a,b);
    printf("%s\n", str);
    free(str);
    return 0;
}

char* expand(char a, char b ){
    char *arr = malloc(sizeof(char)*(b-a+1));
    for(int i=0; i<(b-a+1);++i)
        arr[i]= a+i;
    return arr;
}
void swap(char *a, char *b) {
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}