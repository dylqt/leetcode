#include <iostream>
#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> bkup;
		int index = 0; // index of result
		int addSum = 0;
		if (root == NULL)
			return result;
		// go over the tree, keep a addSum, 
		// if addSum > sum, return 
		DFS(sum, root, bkup, addSum, result, index);
		return result;
	}
private:
	void DFS(int sum, TreeNode* node, vector<int> bkup, int addSum, vector<vector<int>> &result, int &index) {
		if (node == NULL)
			return;
		bkup.push_back(node->val);
		addSum += node->val;
		if (addSum == sum && node->left == NULL & node->right == NULL) {		
			result.push_back(bkup);
		}
		else  {
			DFS(sum, node->left, bkup, addSum, result, index);
			DFS(sum, node->right, bkup, addSum, result, index);
		}
		return;
	}
};

int main()
{
	struct TreeNode root(1);
	root.left = new TreeNode(-2);
	root.right = new TreeNode(-3);
	root.left->left = new TreeNode(1);
	root.left->left->left = new TreeNode(-1);
	
	Solution A;
	vector<vector<int>>result = A.pathSum(&root, -1);
	result[0];
	result[0][0];
	result[0][1];
}