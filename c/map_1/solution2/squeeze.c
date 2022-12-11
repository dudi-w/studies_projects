#include <stdio.h>
#include <string.h>

void squeeze(char *s1,char *s2){
    for(int i= 0 ; i<strlen(s1); ++i ){
        if((*(s1+i))==(*(s2+i))){
            //printf("true %c\n",s1[i] );
            *(s1+i)=-1;
        }
    }
    ///clean the string
    int buffer=0;
    for(int i= 0 ; i<strlen(s1); ++i ){
        if (*(s1+i)!= -1){
            *(s1+buffer)=*(s1+i);
            ++buffer;
        }
    }
    *(s1+buffer)='\0';
}

int main(){
    char s1[] = "wddpddudi";
    char s2[] = "lddoddidi";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}