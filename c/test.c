/***************************************************/
/* */
/* Demo of Cast operator */
/* */
/***************************************************/
#include <stdio.h>
int main() /* Use int float and int */
{	
/*
	float my_float;
	int my_int;
	int my_ch; 
	my_float = 75.345;
	my_int = (int) my_float;
	my_ch = (int) my_float;
	return printf ("Convert from float my_float=%f to my_int=%d and my_ch=%c\n",my_float, my_int, my_ch);;
	
	
	my_int = 69;
	my_float = (float) my_int;
	my_ch = my_int;
	printf ("Convert from int my_int=%d to my_float=%f and my_ch=%c\n",my_int, my_float, my_ch);
	
	
	my_ch = '*';
	my_int = my_ch;
	my_float = (float) my_ch;
	printf ("Convert fsssssssssssssssssrom int my_ch=%c to my_int=%d and my_float=%f\n",my_ch, my_int, my_float);
*/	
	int a =789;
	int b = a;
	a=a+5;
	int c = a;
	int* e = &a;
	a=a+5;
	
	int *f = &b;
	*f= *f+5;
	int q=5;
	int w=7;
	int r= q;
	q=w;
	w=r;
	
	printf ("%d\t%d\t%d\t%d\t%d\n",&a, &b, c ,e, f);
	printf ("%d\t%d\t%d\n",q, w, r);
	printf ("%p\t%p\t%p\n",q, w, r);
	printf ("%d\t%d\t%d\t%d\t%d\n",a, b, c ,*e, *f);	
	return 0;
}
