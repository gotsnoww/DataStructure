#include <stdio.h>
#include "MyLinkedList.h"

int main(void) {
	Node* head_a = NULL;
	Node* head_b = NULL;
	Node* head_c = NULL;

	//a 연결리스트 구성
	Append_Node(&head_a, Create_Node(10));
	Append_Node(&head_a, Create_Node(20));
	Append_Node(&head_a, Create_Node(30));

	//b 연결리스트 구성
	Append_Node(&head_b, Create_Node(15));
	Append_Node(&head_b, Create_Node(25));
	Append_Node(&head_b, Create_Node(27));
	Append_Node(&head_b, Create_Node(28));

	//a,b 연결리스트 출력
	Print_Linked_List(head_a);
	Print_Linked_List(head_b);

	//연결리스트 합병 함수 호출
	head_c = Merge_List(head_a, head_b);

	//합병된 연결리스트 출력
	Print_Linked_List(head_c);

	return 0;
}