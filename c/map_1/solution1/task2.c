#include <stdio.h>

//Check if number is prime or not.
//The user mast get 1 argoment inside fanction.
int main(int argc, char* argv[]){
    printf("%s", *argv);
    int n;
    if (sscanf(argv[1],"%d",&n)== 0){
        printf("\n\7ERROR- argoment is not number\n\7");
        return 0;
    }
    for(int i=2; i<=n/2; ++i){
        printf("%d\n", n);
        if((n%i)==0){
            printf("the number %d is not prime\n", n);
            return 0;
        }
    }
    printf("the number %d prime\n", n);
    return 0;
}