#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL)
		return NULL; 
	struct ListNode *tmp1 = head->next;
	struct ListNode *tmp2 = head;
	
	if (head->next == NULL)
		return head;
	head = head->next;
	tmp2->next = NULL;
	while (head->next != NULL)
	{
		head = head->next;
		tmp1->next = tmp2;
		tmp2 = tmp1;
		tmp1 = head;
	}
	head->next = tmp2;
	return head;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL)
		return NULL;
	struct ListNode* tmp = malloc(sizeof(struct ListNode));
	struct ListNode* tmp2 = NULL;
	tmp->next = head;
/*	while (head->val == val)
	{
		tmp2 = head;
		head = tmp2->next;
		free(tmp2);
		if (head == NULL)
			return NULL;
		tmp = head;
	}
*/	while (tmp->next != NULL)
	{
		if (tmp->next->val == val)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			free(tmp2);			
		}
		else
			tmp = tmp->next;
	}
	return head;
}
int main()
{
	struct ListNode *inp = malloc(sizeof(struct ListNode));
	struct ListNode *inp2 = malloc(sizeof(struct ListNode));
	inp->val = 1;
	inp->next = NULL;
	inp2->val = 2;
	inp2->next = NULL;
	removeElements(inp, 2);
}