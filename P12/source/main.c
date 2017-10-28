#include < stdio.h >
#include < stdlib.h >

int square(int y) {
	return y*y;
}

int main() {
	int x;
	for (x = 1; x <= 10; x++)
		printf("%d ",square( x ) );
	printf("\n\n");
	system(" pause ");
	return 0;
}