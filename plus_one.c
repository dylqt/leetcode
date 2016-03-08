#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	for (int i = 0; i < digitsSize; i++)
	{
		if (digits[digitsSize - i - 1] == 9)
		{
			digits[digitsSize - i - 1] = 0;
			if (i == digitsSize)
			{
				returnSize = malloc((digitsSize + 1) * sizeof(int));
				memset(returnSize, 0, sizeof(returnSize));
				returnSize[0] = 1;
				return returnSize;
			}

		}
		else
		{
			digits[digitsSize - i - 1] += 1;
			returnSize = (int *)malloc((digitsSize)* sizeof(int));
			memcpy(returnSize, digits, digitsSize*sizeof(int));
			return returnSize;
		}
	}
}

int main()
{
	int a[] = { 1, 2, 3 };
	int *b = NULL;
	b = plusOne(a, 3, b);
	printf("%d", b[2]);
}