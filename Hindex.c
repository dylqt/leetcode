#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int hIndex(int* citations, int citationsSize) {
	int B[] = { 1, 2, 4 };
	int *array = (int *)malloc((citationsSize + 1) * sizeof(int));
	for (int i = 0; i < citationsSize + 1; i++)
		array[i] = 0;
	for (int i = 0; i < citationsSize; i++)
	{
		if (citations[i] >= citationsSize)
			array[citationsSize]++;
		else
			array[citations[i]]++;
	}
	if (array[citationsSize] >= citationsSize)
		return citationsSize;
	for (int i = citationsSize - 1; i >= 0; i--)
	{
		array[i] = array[i] + array[i + 1];
		if (array[i] >= i)
			return i;
	}
	return 0;
}
int main()
{
	int A[] = { 1, 3, 1 };
	int a = hIndex(A, 3);
}