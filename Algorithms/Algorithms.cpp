// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"LinkList.h"
#define OneWayLinkReverse
int main()
{
#ifdef OneWayLinkReverse
	OneWayLinkNode* head = InitList(10);
	if (head==NULL)
	{
		printf("Init list failed!\n");
		return 0;
	}
	WalkList(head);
	head = LinkNodeReverse(head);
	WalkList(head);
	CleanList(head);
#endif // OneWayLinkReverse
    return 0;
}

