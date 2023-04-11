#include <stdio.h>
#include "MyDoublyLinkedList.h"

int main() {
	Node* head = NULL;
	DLL_Append_Node(&head, DLL_Create_Node(15));
	DLL_Append_Node(&head, DLL_Create_Node(31));
	DLL_Print_Linked_List(head);

	//DLL_Get_Node() �Լ� ��� �׽�Ʈ
	Node* temp = DLL_Get_Node(head, 0);
	printf("Get_Node() test: %d\n", temp->data);

	//Insert_Node_After() �Լ� ��� �׽�Ʈ
	DLL_Insert_Node_After(DLL_Get_Node(head, 0), DLL_Create_Node(25));
	DLL_Print_Linked_List(head);

	//Remove_Node() �Լ� ��� �׽�Ʈ
	DLL_Remove_Node(&head, DLL_Get_Node(head, 0));
	DLL_Append_Node(&head, DLL_Create_Node(41));

	//���Ḯ��Ʈ ���
	DLL_Print_Linked_List(head);
	DLL_Print_Linked_List_Reverse(DLL_Get_Node(head, 2));
	printf("\n");

	return 0;
}