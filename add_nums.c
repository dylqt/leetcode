#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
    int val;
    struct ListNode *next; 
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	//malloc a list ,check the node until the last one
	struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *head = result;
	int inc = 0;
	while (l1 != NULL || l2 != NULL || inc != 0) {
		int l1_num = 0;
		int l2_num = 0;
		int add_num = 0;
		if (l1 != NULL) {
			l1_num = l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			l2_num = l2->val;
			l2 = l2->next;
		}
		add_num = l1_num + l2_num + inc;
		if (add_num >= 10) {
			inc = 1;
			add_num -= 10;
		}
		else {
			inc = 0;
		}
		struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->val = add_num;
		tmp->next = NULL;
		result->next = tmp;
		result = tmp;
	}
	return head->next;
}

int main()
{
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	struct ListNode *l2 = malloc(sizeof(struct ListNode));
	l1->next = NULL;
	l1->val = 0;
	l2->next = NULL;
	l2->val = 0;
	struct ListNode	*result = addTwoNumbers(l1, l2);
}