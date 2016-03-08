#include <stdio.h>
#include <stdlib.h>


 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode *tmp1 = head->next;    //这里使用了head->next；所以head == NULL判断必须放上面
    struct ListNode *tmp2 = head;
    
    if(head->next == NULL)
        return head;
    head = head->next;
    tmp2->next = NULL;
    while(head->next != NULL)
    {
        head = head->next; 
        tmp1->next = tmp2;
        tmp2 = tmp1;
        tmp1 = head;
    }
    head->next = tmp2;
    return head;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tailA = reverseList(headA);
    struct ListNode *tailB = reverseList(headB);
	struct ListNode *tmpA = NULL; 
	struct ListNode *tmpB = NULL;
	struct ListNode *tmpA2 = tailA; 
	struct ListNode *tmpB2 = tailB;
    while(tailA && tailB)
    {
        if(tailA == tailB)
        {
            tmpA = tailA;
            tmpB = tailB;
            tailA = tailA->next;
            tailB = tailB->next;
        }
        else
        {
            reverseList(tmpA2);
            reverseList(tmpB2);
            return tmpA;
        }
    }
    return NULL;
}

int main()
{
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	struct ListNode *cur = NULL, *next = NULL;
	next = l1;
	int i = 0;
//	cur = l1;
//	int n = 5;
//	int a[5] = { -7, -2, 2, 6, 8};
//	for (int i = 0; i < n; i++)
//	{
//		struct ListNode *tmp = malloc(sizeof(struct ListNode));
//		tmp->val = a[i];
//		tmp->next = NULL;
//		cur->next = tmp;
//		cur = tmp;
//	}
//	struct ListNode *l2 = malloc(sizeof(struct ListNode));
//	struct ListNode *cur2;
//	cur2 = l2;
//	int b[5] = { -10, -6, -6, 6, 8 };
//	for (int i = 0; i < n; i++)
//	{
//		struct ListNode *tmp = malloc(sizeof(struct ListNode));
//		tmp->val = b[i];
//		tmp->next = NULL;
//		cur2->next = tmp;
//		cur2 = tmp;
/	}
//		getIntersectionNode(l1->next, l2->next);
}