#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getSize(int num)
{
	int n = 0;
	if (num == 0)
		return 1;
	while (num)
	{
		n++;
		num /= 10;
	}
	return n;
}
char *my_itoa(int num)
{
	int size = getSize(num);
	char *result = malloc(sizeof(char)* (size + 1));
	result[size] = 0;
	while (size)
	{
		result[size - 1] = num % 10 + '0';
		size--;
		num /= 10;
	}
	return result;
}
int numCmp(int left, int right)
{
	int left_size = getSize(left);
	int right_size = getSize(right);
	int result = 0;
	char *left_c = NULL, *right_c = NULL;
	char *left_tmp = my_itoa(left);
	char *right_tmp = my_itoa(right);
	left_c = malloc(sizeof(char)*(left_size + right_size + 1));
	right_c = malloc(sizeof(char)*(left_size + right_size + 1));

	strcpy_s(left_c, strlen(left_tmp) + 1, left_tmp);
	strcpy_s(right_c, strlen(right_tmp) + 1, right_tmp);
	strcat_s(left_c, left_size + right_size + 1, right_tmp);
	strcat_s(right_c, left_size + right_size + 1, left_tmp);
	result = strcmp(left_c, right_c);
	free(left_tmp);
	free(right_tmp);
	free(left_c);
	free(right_c);
	return result;
}
char* largestNumber(int* nums, int numsSize) {
	int i = 0;
	int max = 0;
	int left = 0, right = 0;
	int n = 0;
	char *result = NULL;
	if (numsSize == 0)
		return NULL;
	for (; i < numsSize; i++)
	{
		max = nums[i];
		for (int j = i + 1; j < numsSize; j++)
		{
			if (numCmp(nums[j], nums[i]) > 0)
			{
				nums[i] = nums[j];
				nums[j] = max;
				max = nums[i];
			}
		}
		n += getSize(max);
	}
	result = (char *)malloc(sizeof(char)* (n + 1));
	result[n] = 0;
	i = 0;
	for (int j = 0; j < numsSize; j++)
	{

		int index = 0;
		max = nums[j];
		index = getSize(max);
		n = index;
		if (max == 0)
			result[i] = '0';
		else{
			while (index)
			{
				result[index + i - 1] = max % 10 + '0';
				max /= 10;
				index--;
			}
		}
		i += n;
	}
	return result;
}
int main()
{
	int nums[] = {1, 0 };
	char *result = largestNumber(nums, 2);
}