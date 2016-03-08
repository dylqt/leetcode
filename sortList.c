#include <stdio.h>

// Definition for singly-linked list.
 struct ListNode {
    int val;
     struct ListNode *next;
 };

 struct ListNode* sortList(struct ListNode* head) {
	 struct ListNode *left = NULL, *right = NULL, *result = NULL, *tmp = NULL;
	 struct ListNode *oneStep = malloc(sizeof(struct ListNode));
	 struct ListNode *twoStep = malloc(sizeof(struct ListNode));
	 struct ListNode *one = oneStep, *two = twoStep;
	 if (head == NULL)
		 return NULL;
	 else if (head->next == NULL)
		 return head;
	 oneStep->next = head;
	 twoStep->next = head;
	 while (twoStep != NULL && twoStep->next != NULL)
	 {
		 oneStep = oneStep->next;
		 twoStep = twoStep->next->next;
	 }
	 right = sortList(oneStep->next);
	 oneStep->next = NULL;
	 left = sortList(head);
	 tmp = malloc(sizeof(struct ListNode));
	 tmp->val = 0;
	 tmp->next = NULL;
	 result = tmp;
	 while (left != NULL && right != NULL)
	 {
		 int a = 10;
		 if (left->val < right->val)
		 {
			 tmp->next = left;
			 left = left->next;
		 }		 
		 else
		 {
			 tmp->next = right;
			 right = right->next;
		 }
		 tmp = tmp->next;
		 tmp->next = NULL;
	 }

	 if(left != NULL)
		 tmp->next = left;
	 if(right != NULL)
		 tmp->next = right;	 
	 tmp = result;
	 result = result->next;
	 free(tmp);
	 free(one);
	 free(two);
	 return result;
 }
int main()
{
	struct ListNode *head = malloc(sizeof(struct ListNode));
	struct ListNode *head_bk = head;
	int a[] = { 3, 4, 1};
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		struct ListNode *tmp = malloc(sizeof(struct ListNode));
		tmp->val = a[i];
		head->next = tmp;
		head = head->next;
	}
	head->next = NULL;
	
	sortList(head_bk->next);
}