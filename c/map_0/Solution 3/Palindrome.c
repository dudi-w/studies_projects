#include <stdio.h>
#include <ctype.h>
int main ()
{
char arr[]={'a','p','f','e','f','p','a'};
char* str ="Apfeefpa";
int checkIfPalindrome = isPalindrome(str , 0,7);
printf("%d\n", checkIfPalindrome);
}

int isPalindrome(char str[], int startFrom,  int n)
{
	printf("fdsadfews\n");
	int checkIfPalindrome = 1;
	while (!isalpha(str[startFrom]))
		startFrom++;
	while (!isalpha(str[n]))
		n--;
	
	
	if ((n > startFrom))
	{
		printf("121212\n");
		if (toupper(str[startFrom]) == toupper(str[n]))
		{
			printf("3535\n");
			checkIfPalindrome = isPalindrome(str, n - 1, startFrom + 1);
		}
		else 
		{
			checkIfPalindrome = 0;
		}
	}
	return (checkIfPalindrome);
}
