#include < stdio.h >
#include < stdlib.h >

char changingTheCase( char x ) {
	if (x >= 'A' && x <= 'Z')
		x += ('a' - 'A');
	else if (x >= 'a' && x <= 'z')
		x -= ('a' - 'A');
	else
		return ' ';
	return x;
}


int main(void) {
	char x,y;
	for (x = 'A'; x <= 'Z'; x++)
	{
		printf("Enter the char : '%c'\t",x);
		y = changingTheCase(x);
		printf("The function return '%c' \n\n", y);
	}
	printf("\n==============================================\n\n\n");
	for (x = 'a'; x <= 'z'; x++)
	{
		printf("Enter the char : '%c'\t", x);
		y = changingTheCase(x);
		printf("The function return '%c' \n\n", y);
	}
	system("pause");
	return 0;
}