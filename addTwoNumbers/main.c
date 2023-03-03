#include <stdio.h>
#include <malloc.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode 
{
	int val;
	struct ListNode* next;
};
#pragma pack(8)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode * visit;
	unsigned char l1_num = 0, l2_num = 0, sum = 0;
	visit = l1;
	while ((visit || l2) || (visit->next != NULL || l2))
	{
		l1_num = 0; l2_num = 0;
		l1_num = visit->val;
		if (l2)
		{
			l2_num = l2->val;
			l2 = l2->next;
		}
		visit->val = (l1_num + l2_num + sum) % 10;
		if (visit->next == NULL && l2)
		{
			visit->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			visit->next->next = NULL;
			visit->next->val = 0;
			visit = visit->next;
		}
		else if (visit && visit->next != NULL)
			visit = visit->next;
		else
		{
			sum = (l1_num + l2_num + sum) / 10;
			break;
		}
		sum = (l1_num + l2_num + sum) / 10;
	}
	if (sum)
	{
		visit->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		visit->next->val = 1;
		visit->next->next = NULL;
	}
	return l1;
}

int main()
{
	//逆序的非负整数
	struct ListNode l1;
	struct ListNode l2;
	struct ListNode* ll;
	int i;
	l1.val = 9;
	l1.next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1.next->val = 9;
	/*l1.next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1.next->next->val = 3;*/
	l1.next->next = NULL;

	l2.val = 9;
	l2.next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2.next->val = 9;
	l2.next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2.next->next->val = 9;
	l2.next->next->next = NULL;

	ll = addTwoNumbers(&l1,&l2);
	for (i=0; ll;i++)
	{
		printf("ll[%d]=%d\t", i,ll->val);
		ll = ll->next;
	}
	

	return 0;
}