#include <stdio.h>

int main()
{
	int var1, var2;
	var1 = 1;
	var2 = 53;
	add_two_numbers (var1, var2);
	var1 = add_two_numbers (1, 22);
	printf("%d\n" , var1);
	exit(0);
}

void add_two_numbers (int a, int b) /* Add a and b */
{
	int c;
	c = a + b;
	return a + b;
}
