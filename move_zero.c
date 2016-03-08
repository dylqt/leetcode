#include <stdio.h>
void moveZeroes(int* nums, int numsSize) {
	int i = 0, j = 0;
	if (numsSize < 2)
		return;
	while (j < numsSize - 1)
	{
		while (nums[i] != 0)
			++i;
		j = i + 1;
		if (j > numsSize - 1)
			return;
		while (nums[j] == 0)
			++j;
		if (j > numsSize - 1)
			return;
		nums[i] = nums[j];
		nums[j] = 0;
	}
}

int main()
{
	int a[] = { 0, 0, 0};
	moveZeroes(a, 3);
	return 0;
}