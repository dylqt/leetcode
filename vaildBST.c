#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define true 1
#define false 0
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

int isValidBST(struct TreeNode* root) {
	int result = true;
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	if (root->left == NULL && root->right != NULL)
	{
		if (root->val >= root->right->val)
			return false;
		if (root->right->left != NULL && root->val >= root->right->left->val)
			return false;
		return isValidBST(root->right);
	}
	if (root->right == NULL && root->left != NULL)
	{
		if (root->val <= root->left->val)
			return false;
		if (root->left->right != NULL && root->left->right >= root->val)
			return false;
		return isValidBST(root->left);
	}
	if (root->left != NULL && root->right != NULL)
	{
		if (root->val <= root->left->val || root->val >= root->right->val)
			return false;
		if (root->right->left != NULL && root->val >= root->right->left->val)
			return false;
		if (root->left->right != NULL && root->left->right >= root->val)
			return false;
		return isValidBST(root->left) & isValidBST(root->right);
	}

}

int main()
{
	printf("%x\n", LONG_MAX);
}