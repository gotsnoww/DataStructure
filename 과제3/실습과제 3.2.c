#include <stdio.h>
#include "MyLinkedList.h"

int main() {
	Node* head = NULL;
	//�⺻ ��� ����
	Append_Node(&head, Create_Node(15));
	Append_Node(&head, Create_Node(31));
	Print_Linked_List(head);

	//Get_Node() �Լ� ��� �׽�Ʈ
	Node* temp = Get_Node(head, 0);
	printf("Get_Node() test: %d\n", temp->data);

	//Insert_Node_After() �Լ� ��� �׽�Ʈ
	Insert_Node_After(Get_Node(head, 0), Create_Node(25));
	Print_Linked_List(head);

	//Remove_Node() �Լ� ��� �׽�Ʈ
	Remove_Node(&head, Get_Node(head, 0));
	Print_Linked_List(head);

	return 0;
}