#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char  *argv[]){
    int symbols , capitalLetter , number ,passlen;
    symbols = capitalLetter = number = passlen = 0;
    printf("%c\n", *(*(argv+1)+1));
    passlen = strlen(*(argv+1));
    if( passlen<4){
        printf("ERROR - Password too short\n");
        return 0;
    }
    
    for(int i=0; i<passlen; ++i){
        if(isupper(*(*(argv+1)+i)))
            capitalLetter= 1;
        if(isdigit(*(*(argv+1)+i)))
            number = 1;
        if(*(*(argv+1)+i)== 33||*(*(argv+1)+i)== 35 ||*(*(argv+1)+i)== 37)
            symbols = 1;
    }

    if(!symbols || !capitalLetter || !number){
        printf("password is not strong\n");
        return 0;
    }
    printf("password is strong\n");
    return 0;
}