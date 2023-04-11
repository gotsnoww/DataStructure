#include <stdio.h>
#include "MyDoublyLinkedList.h"

int main() {
	Node* head = NULL;
	DLL_Append_Node(&head, DLL_Create_Node(15));
	DLL_Append_Node(&head, DLL_Create_Node(31));
	DLL_Print_Linked_List(head);

	//DLL_Get_Node() 함수 기능 테스트
	Node* temp = DLL_Get_Node(head, 0);
	printf("Get_Node() test: %d\n", temp->data);

	//Insert_Node_After() 함수 기능 테스트
	DLL_Insert_Node_After(DLL_Get_Node(head, 0), DLL_Create_Node(25));
	DLL_Print_Linked_List(head);

	//Remove_Node() 함수 기능 테스트
	DLL_Remove_Node(&head, DLL_Get_Node(head, 0));
	DLL_Append_Node(&head, DLL_Create_Node(41));

	//연결리스트 출력
	DLL_Print_Linked_List(head);
	DLL_Print_Linked_List_Reverse(DLL_Get_Node(head, 2));
	printf("\n");

	return 0;
}