#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};
int* InorderTraversal(struct TreeNode* root, int* returnSize, int *result) {
	if (root == NULL)
		return result;
	
	InorderTraversal(root->left, returnSize, result);	
	
	(*returnSize)++;
	result = realloc(result, (*returnSize + 1) * sizeof(int));
	result[*returnSize] = root->val;
	InorderTraversal(root->right, returnSize, result);
	return result ;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int *result = malloc(sizeof(int));
	result[0] = 0;
	*returnSize = 0;
	result = InorderTraversal(root, returnSize, result);
	
	return result + 1;
}

int main()
{
	int returnSize = 0;
	
/*	struct TreeNode *left = malloc(sizeof(struct TreeNode));
	left->left = NULL;
	left->right = NULL;
	left->val = 2;
	struct TreeNode *right = malloc(sizeof(struct TreeNode));
	right->left = NULL;
	right->right = NULL;
	right->val = 2;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	root->left = left;
	root->right = right;
	root->val = 1;
	*/
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	root->left = NULL;
	root->right = NULL;
	root->val = 1;
	int *result = inorderTraversal(root, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", result[i]);
	}
	putchar('\n');
}