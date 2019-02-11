#include "LinkedList.h"
#define MAXBUF 1024

int main() {

	char buf[MAXBUF];
	Node *List = NULL;

	while (1) {
		system("cls");
		PrintList(List);

		memset(buf, 0, MAXBUF);
		printf("\n>>> Input your data: ");
		fgets(buf, MAXBUF, stdin);

		if (strncmp(buf, "#exit", strlen("#exit")) == 0) break;
		else if (strncmp(buf, "#delete", strlen("#delete")) == 0) {
			memset(buf, 0, MAXBUF);
			printf(" > Delete node data: ");
			fgets(buf, MAXBUF, stdin);

			DeleteNode(&List, buf);
		} else if (strncmp(buf, "#insert", strlen("#insert")) == 0) {
			char tData[MAXBUF];
			memset(tData, 0, MAXBUF);
			memset(buf, 0, MAXBUF);
			printf(" > Target node data: ");
			fgets(tData, MAXBUF, stdin);
			printf(" > New node data: ");
			fgets(buf, MAXBUF, stdin);

			InsertNode(&List, tData, buf);
		} else AppendNode(&List, CreateNode(buf));
	}
	
	DeleteList(List);
	List = NULL;
	PrintList(List);

	system("PAUSE");
	return 0;
}