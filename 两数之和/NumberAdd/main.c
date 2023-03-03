#include <stdio.h>
#include <malloc.h>

typedef struct ele
{
	int key;
	int value;
}Element;

typedef struct node
{
	Element* Ele;
	struct node* next;
	int length;
}Node;

struct HashTable
{
	Node** map;
	int length;
};
struct HashTable* Hash_Table;
unsigned char hash(int key)
{
	if (key < 10)
		return key;
	return key = key %10;
}
void hashTableInit(struct HashTable** Hash_Table)
{
	int i;
	*Hash_Table = (struct HashTable*)malloc(sizeof(struct HashTable));
	(*Hash_Table)->length = 10;
	(*Hash_Table)->map = (Node**)malloc(sizeof(Node*)*(*Hash_Table)->length);
	for (i = 0; i < 10; i++)
	{
		(*Hash_Table)->map[i] = (Node*)malloc(sizeof(Node));
		(*Hash_Table)->map[i]->Ele = NULL;
		(*Hash_Table)->map[i]->next = NULL;
		(*Hash_Table)->map[i]->length = 0;
	}
}
Node* find(int key)
{
	Node* tmd;
	int i,nkey=key;
	unsigned char ikey;
	if (nkey < 0)
	{
		nkey = ~(nkey - 1);
	}
	ikey = hash(nkey);
	if (Hash_Table->map[ikey]->Ele == NULL)
		return NULL;
	tmd = Hash_Table->map[ikey];

	for (i = 0; i < Hash_Table->map[ikey]->length; i++)
	{
		if (tmd->Ele->key == key)
			return tmd;
		tmd = tmd->next;
	}
	return NULL;

}

Node* insert(int key,int value)
{
	Node* tmd;
	int i, nkey = key;
	unsigned char ikey;
	if (nkey < 0)
	{
		nkey = ~(nkey - 1);
	}
	ikey = hash(nkey);
	if (Hash_Table->map[ikey]->Ele == NULL)
	{
		//Hash_Table->map[ikey] = (Node*)malloc(sizeof(Node));
		Hash_Table->map[ikey]->Ele = (Element*)malloc(sizeof(Element));
		tmd = Hash_Table->map[ikey];
		tmd->Ele->key = key;
		tmd->Ele->value = value;
		tmd->next = NULL;
		Hash_Table->map[ikey]->length += 1;
		return tmd;
	}
	tmd = Hash_Table->map[ikey];
	for (i = 0; i < Hash_Table->map[ikey]->length-1; i++)
	{
		tmd = tmd->next;
	}
	tmd->next = (Node*)malloc(sizeof(Node));
	tmd = tmd->next;
	tmd->Ele = (Element*)malloc(sizeof(Element));
	tmd->Ele->key = key;
	tmd->Ele->value = value;
	Hash_Table->map[ikey]->length += 1;
	return tmd;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i,*num;
	Node* tmd;
	hashTableInit(&Hash_Table);
	for (i = 0; i < numsSize; i++)
	{
		tmd = find(target - nums[i]);
		if (tmd != NULL)
		{
			num = (int*)malloc(sizeof(int)*2);
			num[0] = tmd->Ele->value;
			num[1] = i;
			*returnSize = 2;
			return num;
		}
		
		insert(nums[i],i);
	}
	*returnSize = 0;
	return NULL;
}

int main() {
	int target = 100;
	int nums[3] = { 5,75,25 };
	int a,*num;
	num = twoSum(nums, 3, target, &a);
	printf("num[0]=%d\tnum[1]=%d", num[0], num[1]);
	return 0;
}