#include < stdio.h >
#include < stdlib.h >

double Power(double x, int n) {
	int i;
	double PowerXn = 1;
	for (i = 1; i <= n; i++)
		PowerXn *= x;
	return PowerXn;

}

int main( void ) {
	int k; double Ans;
	printf( "�p��3.5��k����?�п�J k = " );
	scanf_s( "%d",&k );
	Ans = Power( 3.5, k );
	printf( "3.5��%d���� = %f \n", k, Ans );
	system("pause");
	return 0;
}