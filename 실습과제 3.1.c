#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

Node* Create_Node(int newData);
void Destory_Node(Node* node);
void Append_Node(Node** head, Node* newNode);
void Print_Linked_List(Node* head);

int main() {
	Node* head = NULL;
	Node* newNode = NULL;

	newNode = Create_Node(15);
	Append_Node(&head, newNode);

	newNode = Create_Node(31);
	Append_Node(&head, newNode);

	Print_Linked_List(head);

	return 0;
}

Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->link = NULL;
	return newNode;
}

void Destory_Node(Node* node) {
	if (node != NULL)
		free(node);
}

void Append_Node(Node** head, Node* newNode) {
	if ((*head) = NULL)
		head = newNode;
	else {
		tail = head;

	}
}

void Print_Linked_List(Node* head) {
	Node* iter = head;
	int i = 0;
	while (iter != NULL) {
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf("->");
		i++;
	}
	printf("\n");
}