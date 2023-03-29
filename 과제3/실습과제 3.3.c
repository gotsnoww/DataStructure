#include <stdio.h>
#include "MyLinkedList.h"

int main() {
	Node* head = NULL;

	Append_Node(&head, Create_Node(15));
	Append_Node(&head, Create_Node(25));
	Append_Node(&head, Create_Node(31));
	Append_Node(&head, Create_Node(24));

	Print_Linked_List(head);

	Node* reverse = Reverse_List(head);

	Print_Linked_List(reverse);
	printf("\n");
	
	return 0;
}