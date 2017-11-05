#include < stdio.h >
#include < stdlib.h >

double power( double base, int exponent ) {
	if (exponent != 0)
		return base * power(base, exponent - 1);
	else
		return 1;
}

int main( void ) {
	double x;
	int i;
	printf("Enter oen number : ");
	scanf_s("%lf",&x);
	printf("\n");
	for( i = 0; i <= 10; i++ )
	 printf( "power(%.2lf,%d) = %.2lf\n",x ,i, power(x,i) );
	printf("\n");
	system("pause");
	return 0;
}