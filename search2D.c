#include <stdio.h>
int searchMatrix(int **matrix, int matrixRowSize, int matrixColSize, int target) {
	int i = matrixRowSize, j = matrixColSize;
	printf("%x > %x > %x > %x", matrix, matrix[0][1], matrix[0], matrix[1]);
	
	while (i && j)
	{
		i--;
		j--;
		if (matrix[i][j] <= target)
			break;
	}
	if (!i && j)
	{
		for (int k = 0; k < j; k++)
		{
			if (matrix[0][k] == target)
				return 1;
		}
		return 0;
	}
	if (!j && i)
	{
		for (int k = 0; k < i; k++)
		{
			if (matrix[k][0] == target)
				return 1;
		}
		return 0;
	}
	if (matrix[i][j] == target)
		return 1;
	if (i == matrixColSize - 1)
		return 0;
	for (int k = 0; k < i; k++)
	{
		if (matrix[k][j + 1] == target)
			return 1;
	}
	for (int k = 0; k < j; k++)
	{
		if (matrix[i + 1][k] == target)
			return 1;
	}

	return 0;
}
int b[][2] = { { 1, 4 }, { 2, 5 } };
int main()
{
	int c[][2] = { { 1, 4 }, { 2, 5 } };
	int d = 0;
	printf("%x", &d);
	int **a = malloc(sizeof(int *)* 2);
	*a = malloc(sizeof(int)* 2);
	*(a + 1) = malloc(sizeof(int)* 2);
	a[0][0] = 0;
	a[0][1] = 1;
	*(*(a+1) ) = 2;
	*(*(a + 1) + 1) = 3;
	searchMatrix(a, 2, 2, 2);
}