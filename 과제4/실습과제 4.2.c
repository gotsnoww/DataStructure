#include <stdio.h>
#include "MyLinkedList.h"

//연결리스트 합병 함수
Node* Merge_List(Node* head_a, Node* head_b) {
	Node* head_c = NULL;

	//연결리스트 a와 b에 데이터가 남아있는 동안 반복
	while (head_a != NULL && head_b != NULL) { 
		if (head_a->data < head_b->data) { //연결리스트 a의 head data값이 b의 head data값보다 작을경우
			Append_Node(&head_c, Create_Node(head_a->data)); //연결리스트 c에 a의 head data 추가
			head_a = head_a->link; //a의 head를 다음 노드(link)로 이동
		}
		else { // a->data > b->data
			Append_Node(&head_c, Create_Node(head_b->data));
			head_b = head_b->link;
		}
	}

	//연결리스트 a의 잔여항 처리
	while (head_a != NULL)
	{
		Append_Node(&head_c, Create_Node(head_a->data));
		head_a = head_a->link;
	}
	//연결리스트 b의 잔여항 처리
	while (head_b != NULL)
	{
		Append_Node(&head_c, Create_Node(head_b->data));
		head_b = head_b->link;
	}

	return head_c;
}

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


- 과제에 대한 고찰
두 개의 연결리스트를 하나의 연결리스트로 합병하는 프로그램 코드를 짜보았다. 
새롭게 추가 된 연결리스트 합병 함수는 연결리스트 a와 b를 인자로 받아서 
연결리스트 a와 b의 data 값을 서로 비교해보고 연결리스트 c에 그 값을 저장하도록 동작한다.
연결리스트 a와 b중 하나의 연결리스트의 값이 NULL이 되더라도 나머지 하나의 연결리스트에는
값이 남아있을 수 있기에 잔여항을 처리하는 코드도 필요하다.
위 프로그램의 수행시간은 연결리스트 a와 b의 노드의 수에 비례한다. 
예를들어 a의 노드의 수가 n이고 b의 노드의 수가 m이면 수행시간은 O(n+m)이 되겠다.
수행공간또한 연결리스트 a와 b의 크기에 비례한다.
하지만 이렇게 구현된 연결리스트는 연결리스트 c를 메모리에 동적할당하여 사용함으로써
추가적인 메모리 공간이 필요하다. 메모리 효율적인 측면에서는 연결리스트 a, b 두 개만을
이용하여 합병하는 방법이 좋을 것 같다.
