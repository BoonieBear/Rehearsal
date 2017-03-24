#include"stdafx.h"
#include"LinkList.h"
void WalkList(OneWayLinkNode* head)
{
	printf("Print list node one by one\n");
	OneWayLinkNode* pNode = head;
	while (pNode != NULL&&pNode->Next!=NULL)
	{
		printf("%d ",pNode->value);
		pNode = pNode->Next;
	}
	printf("%d ", pNode->value);
}
OneWayLinkNode* InitList(int n)
{
	OneWayLinkNode* pNode = new OneWayLinkNode;
	OneWayLinkNode* head = pNode;
	for (int i = 0; i < n-1; i++)
	{
		pNode->value = i;
		pNode->Next = new OneWayLinkNode;
		pNode = pNode->Next;
	}
	pNode->value = n-1;
	pNode->Next = NULL;
	
	return head;
	
}
void CleanList(OneWayLinkNode* head)
{
	OneWayLinkNode* pNode = head;
	while (head !=NULL&&head->Next!=NULL)
	{
		head = head->Next;
		delete pNode;
	}
	delete head;
	head = NULL;
}
void LinkNodeReverse(OneWayLinkNode* head)
{
	OneWayLinkNode* pNode = head;
	while (pNode != NULL&&pNode->Next!=NULL)
	{
		head = pNode->Next;
		if (head->Next != NULL)
			pNode->Next = head->Next;
		head->Next = pNode; 
	}
}