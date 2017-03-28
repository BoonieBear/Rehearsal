#pragma once
#include"stdafx.h"
struct OneWayLinkNode {
	int value;
	OneWayLinkNode* Next;
};
void WalkList(OneWayLinkNode* head);
OneWayLinkNode* InitList(int n);
void CleanList(OneWayLinkNode* head);
OneWayLinkNode* LinkNodeReverse(OneWayLinkNode* head);
