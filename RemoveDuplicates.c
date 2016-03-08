#include <stdio.h>
#include <stdlib.h>

// int removeDuplicates(int* nums, int numsSize) {
// 	int i = 0;
// 	int j = 1;
// 	int k = 0;
// 	while (i < numsSize)
// 	{
// 		for (; j < numsSize; j++)
// 		{
// 			if (nums[i] == nums[j])
// 				nums[j] = -1;
// 		}
// 		i++;
// 		while (nums[i] == -1)
// 			i++;
// 		j = i + 1;
// 	}
// 	i = 1;
// 	j = 2;
// 	while (j < numsSize)
// 	{
// 		while(nums[j] == -1)
// 			j++;
// 		nums[i] = nums[j];
// 		i++;
// 		j++;
// 	}
// 	return i;
// }

// typedef struct Node
// {
// 	int data;
// 	struct Node *next;
// }*NODE, *LIST;

// int isExist(LIST l, int num)
// {
// 	l = l->next;
// 	while (l != NULL)
// 	{
// 		if (l->data == num)
// 			return 1;
// 		l = l->next;
// 	}
// 	return 0;
// }
// 
// int pushList(LIST l, int num)
// {
// 	NODE tmp = (NODE)malloc(sizeof(struct Node));
// 	if (tmp == NULL)
// 	{
// 		printf("malloc error\n");
// 		return 0;
// 	}
// 	tmp->data = num;
// 	tmp->next = l->next;
// 	l->next = tmp;
// 	return 1;
// }
// 
// int insertList(LIST l, int num)
// {
// 	NODE tmp = NULL;
// 	while (l->next != NULL)
// 	{
// 		l = l->next;
// 		if (l->data == num)
// 		{
// 			return 0;
// 		}
// 	}
// 	tmp = (NODE)malloc(sizeof(struct Node));
// 	if (tmp == NULL)
// 	{
// 		return -1;
// 	}
// 	tmp->data = num;
// 	tmp->next = NULL;
// 	l->next = tmp;
// 	return 1;
// }
// void printList(LIST l)
// {
// 	l = l->next;
// 	printf("root");
// 	while (l != NULL)
// 	{
// 		printf("->%d", l->data);
// 		l = l->next;
// 	}
// 	printf("\n");
// }
// 
// int removeDuplicates(int* nums, int numsSize) {
// 	int i = 0;
// 	LIST root = (LIST)malloc(sizeof(struct Node));
// 	root->data = 0;
// 	root->next = NULL;
// 	for (int i = 0; i < numsSize; i++)
// 	{
// 		insertList(root, nums[i]);
// 	}
// 	printList(root);
// 	i = 0;
// 	while (root->next != NULL)
// 	{
// 		root = root->next;
// 		nums[i] = root->data;		
// 		i++;
// 	}
// 	
// 	return i;
// }

int removeDuplicates(int* nums, int numsSize) {
	if (!numsSize)
		return 0;
	int num = 1, i;
	for (i = 1; i < numsSize; ++i)
	{
		if (nums[i] != nums[i - 1])
			nums[num++] = nums[i];
	}
	return num;
}
int main()
{
 	int a[] = { 1, 1, 2, 3, 2, 4, 5, 3, 4};
	removeDuplicates(a, 9);
}