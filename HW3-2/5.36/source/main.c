//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//             佛祖保佑 106360231 永無bug
//
//***************************************************
#include < stdio.h >
#include < stdlib.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void printDisk(int *disk, int disk_num) {
	int i, j, k, upper = 0;
	int n[3] = { 0 }, *p[3];

	for (i = 0; i < 3; i++)
		p[i] = (int *)calloc(disk_num, sizeof(int));

	for (i = 0; i < 3; i++)
		for (j = 0; j < disk_num; j++)
			p[i][j] = -1;

	for (j = 0; j < 3; j++) {
		for (k = 0; k < 3; k++) {
			for (i = 0; i < disk_num * 2; i++)
				printf(" ");
			printf("||");
		}
		printf("\n");
	}

	for (j = 0; j < disk_num; j++)
	{
		p[disk[j]][n[disk[j]]++] = j;
	}
	for (i = 0; i < 3; i++)
		for (j = disk_num - 1; j > 0; j--)
			for (k = 0; k < j; k++)
				if (p[i][k] > p[i][k + 1])
					swap(&p[i][k], &p[i][k + 1]);

	//for (i = 0; i < 3; i++)
	//{
	//	printf("p[%d] : ", i);
	//	for (j = 0; j < 15; j++)
	//		printf("%d, ",p[i][j]);
	//	printf("\n");
	//}

	for (i = 0; i < disk_num; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (p[j][i] == -1)
			{
				for (k = 0; k < disk_num * 2 - upper; k++)
					printf(" ");
				printf("||");
				upper = 0;
			}
			else
			{
				for (k = 0; k <= (disk_num * 2 - upper - p[j][i] - 2); k++)
					printf(" ");
				for (k = 0; k <= (p[j][i]); k++)
					printf("=");
				printf("%.2d", p[j][i]);
				for (k = 0; k <= (p[j][i]); k++)
					printf("=");
				upper = p[j][i] + 1;
			}
		}
		upper = 0;
		printf("\n");
	}

	printf("\n\n");
	for (i = 0; i < disk_num * 8; i++)
		printf("*");
	printf("\n");

	for (i = 0; i < 3; i++)
		free(p[i]);

	for (i = 0; i < 10000; i++)
		for (j = 0; j < 10000; j++);

	return;
}

unsigned long long int totalMoveOfHanoi(int disk) {
	if (disk != 1)
		return 2 * totalMoveOfHanoi(disk - 1) + 1;
	else
		return 1;
}

void TowerOfHanoi(int *disk, int disk_num, int n, int a, int c, int b) {
	int i = 0;
	static long long int total_move = 0, move_step = 1;
	total_move = totalMoveOfHanoi(disk_num);
	if (n >= 1)
	{
		TowerOfHanoi(disk, disk_num, n - 1, a, b, c);
		while (disk[i] != a) i++;
		disk[i] = c;
		system("cls");
		printf("total_move : %lld \t move_step : %lld (%.2lf%%)\n\n", total_move, move_step, (double)move_step / total_move * 100);
		printDisk(disk, disk_num);
		move_step++;
		TowerOfHanoi(disk, disk_num, n - 1, b, c, a);
	}
}

int main(void) {
	int disk_num;
	int *disk;
	printf("請輸入盤子數 : ");
	scanf_s("%d", &disk_num);
	long long int total_move, move_step = 0;
	disk = (int *)calloc(disk_num, sizeof(int));
	total_move = totalMoveOfHanoi(disk_num);
	TowerOfHanoi(disk, disk_num, disk_num, 0, 2, 1);
	free(disk);
	system("pause");
	return 0;
}