#include <stdio.h>
#include <stdlib.h>
void printArray(int *nums, int numsSize);
void merge(int *nums, int start, int mid, int end)
{
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	int i = 0, j = 0;
	int *left = malloc(sizeof(int)* (leftSize + 1));
	int *right = malloc(sizeof(int)* (rightSize + 1) );
	for (int i = 0; i < leftSize; i++)
		left[i] = nums[start + i];
	left[leftSize] = -9999;
	for (int i = 0; i < rightSize; i++)
		right[i] = nums[mid + i + 1];
	right[rightSize] = -9999;
	for (int k = start; k <= end; k++)
	{
		if (left[i] > right[j])
		{
			nums[k] = left[i];
			i++;
		}
		else
		{
			nums[k] = right[j];
			j++;
		}
	}
	free(left);
	free(right);
}
void mergeSort(int *nums, int start, int end)
{
	int mid = (start + end) / 2;
	if (start < end)
	{
		mergeSort(nums, start, mid);
		mergeSort(nums, mid + 1, end);
		merge(nums, start, mid, end);
	}
}
int findKthLargest(int* nums, int numsSize, int k) {
	mergeSort(nums, 0, numsSize - 1);
	printArray(nums, numsSize);
	return nums[k - 1];
}

void printArray(int *nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++)
		printf("%d", nums[i]);
	printf("\n");
}
int main()
{
	int a[] = { 3, 2, 5, 4, 7};	
	//printArray(a, 27);
	int b = findKthLargest(a, sizeof(a) / sizeof(int), 2);
}