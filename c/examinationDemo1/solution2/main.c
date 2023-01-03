#include <stdlib.h>
#include <stdlib.h>
#include "solution2.h"

int main(){
    int n1=0; int n2=0; int num = 900;//num must by even number
    int *arrPrime = creatArrPrimes(10000);
    findPrimes(arrPrime, 1229, num, &n1 ,&n2);
    free(arrPrime);
    printf("%d + %d = %d\n" , n1 ,n2 ,num);
    return 0;
}