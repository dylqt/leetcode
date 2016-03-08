#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* tmp = malloc(sizeof(struct ListNode));
	struct ListNode* head = tmp;
	struct ListNode* nextP;

	while (l1 != NULL && l2 != NULL)
	{
		nextP = malloc(sizeof(struct ListNode));
		if (l1->val < l2->val)
		{
			nextP->val = l1->val;
			nextP->next = NULL;
			tmp->next = nextP;
			tmp = nextP;
			l1 = l1->next;
			continue;
		}
		if (l1->val > l2->val)
		{
			nextP->val = l2->val;
			nextP->next = NULL;
			tmp->next = nextP;
			tmp = nextP;
			l2 = l2->next;
			continue;
		}
		if (l1->val == l2->val)
		{
			struct ListNode *twice = malloc(sizeof(struct ListNode));
			twice->val = l1->val;
			twice->next = nextP;
			nextP->val = l1->val;
			nextP->next = NULL;
			tmp->next = twice;
			tmp = nextP;
			l1 = l1->next;
			l2 = l2->next;
			continue;
		}
	}
	if (l1 == NULL)
	{
		tmp->next = l2;
		return head->next;
	}
	if (l2 == NULL)
	{
		tmp->next = l1;
		return head->next;
	}
	return head->next;
}





int main()
{
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	struct ListNode *cur;
	cur = l1;
	int n = 5;
	int a[5] = { -7, -2, 2, 4, 6 };
	for (int i = 0; i < n; i++)
	{
		struct ListNode *tmp = malloc(sizeof(struct ListNode));
		tmp->val = a[i];
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	struct ListNode *l2 = malloc(sizeof(struct ListNode));
	struct ListNode *cur2;
	cur2 = l2;
	int b[5] = { -10, -6, -6, 6, 8 };
	for (int i = 0; i < n; i++)
	{
		struct ListNode *tmp = malloc(sizeof(struct ListNode));
		tmp->val = b[i];
		tmp->next = NULL;
		cur2->next = tmp;
		cur2 = tmp;
	}
	mergeTwoLists(l1->next, l2->next);
}