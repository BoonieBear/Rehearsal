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
	printf("\n");
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
	OneWayLinkNode* pNode = NULL;
	while (head !=NULL&&head->Next!=NULL)
	{
		pNode = head;
		head = head->Next;
		delete pNode;
	}
	delete head;
	head = NULL;
}
OneWayLinkNode* LinkNodeReverse(OneWayLinkNode* head)
{
	OneWayLinkNode* pNode = head;
	OneWayLinkNode* pTmp = NULL;
	while (pNode != NULL&&pNode->Next!=NULL)
	{
		pTmp = pNode->Next->Next;

		pNode->Next->Next = head;
		head = pNode->Next;
		pNode->Next = pTmp;

		WalkList(head);
	}
	return head;
}