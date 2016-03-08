#include <stdio.h>

void sortColors(int* nums, int numsSize) {
	int red = 0, white = 0, blue = 0;
	for (int i = 0; i < numsSize; i++)
	{
		switch (nums[i])
		{
		case 0:
			red++;
			break;
		case 1:
			white++;
			break;
		case 2:
			blue++;
			break;
		}
	}
	for (int i = 0; i < numsSize;)
	{
		if (red-- > 0)
			nums[i++] = 0;
		if (white-- > 0)
			nums[i++] = 1;
		if (blue-- > 0)
			nums[i++] = 2;
	}

}

int main()
{
	int nums[] = { 0, 0, 0, 1, 1, 0 };
	sortColors(nums, 6);
}