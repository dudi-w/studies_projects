#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int tmp_a, tmp_b;
    tmp_a = *a;
    tmp_b = *b;
    *a = tmp_a+tmp_b;
    *b= abs(tmp_a-tmp_b);
}

int main()
{
    int a = 3;
    int b = 7;
    printf("%d\t%d\n" ,a, b );
    swap(&a, &b);
    printf("%d\t%d\n" ,a, b );
}
