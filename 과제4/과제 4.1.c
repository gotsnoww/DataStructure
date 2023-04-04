#include <stdio.h>
#include "MyLinkedList.h"

int main() {
	Node* head = NULL;

	Append_Node(&head, Create_Node(15));
	Append_Node(&head, Create_Node(25));
	Append_Node(&head, Create_Node(31));
	Append_Node(&head, Create_Node(24));

	Print_Circular_Linked_List(head);

	return 0;
}
