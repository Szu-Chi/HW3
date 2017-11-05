#include < stdio.h >
#include < stdlib.h >

unsigned long long int max_fibonacci( void ) {
	unsigned long long int  j = 0, k = 1, ans = 1;
	while (ans >= k) {
		j = k;
		k = ans;
		ans = j + k;
	}
	return k;
}

unsigned long long int fibonacci( unsigned int i) {
	unsigned long long int  j = 0, k = 1, ans = 1;
	if (i == 1)
		return 0;
	else if (i == 2)
		return 1;
	else
	while (i-- != 3) {
		j = k;
		k = ans;
		ans = j + k;
	}
	return ans;
}
int main( void ) {
	int i;
	scanf_s("%d",&i);
	printf("fibonacci(%u) = %llu\n",i ,fibonacci(i));
	printf("The largest Fibonacii number that can be printed on my system is %llu", max_fibonacci());
	printf("\n");
	system("pause");
	return 0;
}