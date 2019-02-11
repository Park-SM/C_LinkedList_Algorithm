#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
	char *data;
	struct tagNode *NextNode;
}Node;

Node* CreateNode(Node *nData);
void AppendNode(Node **HeadNode, Node *NewNode);
void PrintList(Node *PrintNode);
int DeleteList(Node *DeleteNode);
void DestroyNode(Node *dNode);
int InsertNode(Node **HeadNode, char *TargetData, char *NewData);
int DeleteNode(Node **HeadNode, char *TargetData);
int CountingList(Node *Current);

#endif