#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
	int i = 0;
	int n = 0;
	int j = 0;
	if (numsSize == 1)
	if (nums[0] == val)
		return 0;
	while (i < numsSize - j)
	{
		if (nums[i] == val)
		{
			nums[i] = nums[numsSize - j - 1];
			j++;
			n++;
			continue;
		}
		else
		{
			i++;
		}
	}
	return numsSize - n;
}

int main()
{
	int a[] = { 3, 3 };
	removeElement(a, 2, 3);
}