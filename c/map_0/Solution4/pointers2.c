#include <stdio.h>

void swap(int **a, int **b)
{
	int *tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int main()
{   
	int arr_a[ ] = {5,3,2,6};
	int arr_b[ ] = {6,9,2,5,7,3};
	int* a = arr_a;
	int* b = arr_b;
	swap(&a, &b);
	//printf("%d", *(b+1)) ;
}
