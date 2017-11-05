#include < stdio.h >
#include < stdlib.h >

int leastCommonM( int x,int y ) {
	int i = 1;
	while ( (x * i) % y != 0 ) i++;
	return x * i;
}


int main( void ) {
	int i,j;
	printf("Enter two integer : ");
	scanf_s("%d %d",&i,&j);
	printf("The least common multiple is %d\n", leastCommonM( i, j ));

	system("pause");
	return 0;
}