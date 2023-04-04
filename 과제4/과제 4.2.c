#include <stdio.h>
#include "MyLinkedList.h"

int main(void) {
	Node* tail = NULL;

	Append_Node_T(&tail, Create_Node(15));
	Append_Node_T(&tail, Create_Node(25));
	Append_Node_T(&tail, Create_Node(31));
	Append_Node_T(&tail, Create_Node(24));

	Print_Circular_Linked_List_T(tail);
	
	return 0;
}