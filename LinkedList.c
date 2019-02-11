#include "LinkedList.h"

// Return address of the new node.
Node* CreateNode(Node *nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = (char*)malloc(strlen(nData) + 1);	// + 1 is NULL's space.

	strncpy(NewNode->data, nData, strlen(nData) + 1);	// + 1 is NULL's space.
	NewNode->NextNode = NULL;

	return NewNode;
}

void AppendNode(Node **HeadNode, Node *NewNode) {
	if (*HeadNode == NULL) {	// If the list is empty.
		*HeadNode = NewNode;
	} else {
		Node *TailNode = *HeadNode;
		while (TailNode->NextNode != NULL) TailNode = TailNode->NextNode;
		TailNode->NextNode = NewNode;
	}
}

void PrintList(Node *PrintNode) {
	if (PrintNode != NULL) {
		while (PrintNode != NULL) {
			printf("> %s", PrintNode->data);
			PrintNode = PrintNode->NextNode;
		}
	} else printf("> :: No data ::\n");
}

// If the list is empty, return value is 0.
int DeleteList(Node *DeleteNode) {
	if (DeleteNode != NULL) {		// If the list is not empty.
		if (DeleteNode->NextNode != NULL) DeleteList(DeleteNode->NextNode);
		DestroyNode(DeleteNode);

		return 1;
	}
	return 0;
}

void DestroyNode(Node *dNode) {
	free(dNode->data);
	free(dNode);
}

// If return value is 2, the list is empty.
// If return value is 1, there is no matched node for the target data.
// If return value is 0, is successful.
int InsertNode(Node **HeadNode, char *TargetData, char *NewData) {	
	if (*HeadNode != NULL) {		// If the list is not empty.			
		Node *Current = *HeadNode;									
		while (Current != NULL && strncmp(Current->data, TargetData, strlen(TargetData)) != 0) {
			Current = Current->NextNode;
		}
		if (Current == NULL) return 1;				// If there is no matched node for the target data.
		if (Current == *HeadNode) {					// If head of the list is matched the target data. 
			Node *NewNode = CreateNode(NewData);
			NewNode->NextNode = Current;
			*HeadNode = NewNode;
			return 0;
		}
		Node *NewNode = CreateNode(NewData);
		NewNode->NextNode = Current->NextNode;
		Current->NextNode = NewNode;
		return 0;
	}
	return 2;		// If the list is empty.
}

// If return value is 2, the list is empty.
// If return value is 1, there is no matched node for the target data.
// If return value is 0, is successful.
int DeleteNode(Node **HeadNode, char *TargetData) {
	if (*HeadNode != NULL) {		// If the list is not empty.			
		Node *Current = *HeadNode;
		Node *Temp = NULL;
		while (Current != NULL && strncmp(Current->data, TargetData, strlen(TargetData)) != 0) {
			Temp = Current;
			Current = Current->NextNode;
		}
		if (Current == NULL) return 1;		// If there is no matched node for the target data.
		if (Temp == NULL) {					// If head of the list is matched the target data. 
			*HeadNode = Current->NextNode;
			DestroyNode(Current);
			return 0;
		}
		Temp->NextNode = Current->NextNode;
		DestroyNode(Current);

	}
	return 2;		// If the list is empty.
}

// If return value is -1, the list is empty.
int CountingList(Node *Current) {
	if (Current != NULL) {
		int count = 0;
		while (Current != NULL) {
			count++;
			Current = Current->NextNode;
		}
		return count;
	}
	return -1;
}