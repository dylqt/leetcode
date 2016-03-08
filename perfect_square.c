#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int numSquares(int n) {
	//����n����С�����飬��ʼ��Ϊ0
	int *result = calloc((n + 1), sizeof(int));
	//����ƽ����ֵ
	int sqrtn = sqrt(n);
	result[1] = 1;
	for (int i = 2; i <= n; i++){
		int min = n;
		int j = 1;
		while (j * j <= i){
			if (min > result[i - j*j] + 1)
				min = result[i - j*j] + 1;
			j++;
		}
		result[i] = min;
	}
	return result[n];
}

int main()
{
	printf("%d\n",numSquares(12));
	for (int i = 1; i < 20; i++)
	{
		printf("%d : %d\n", i, numSquares(i));
	}
}