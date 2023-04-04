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


- 과제에 대한 고찰

역연결리스트를 구현하는 과제를 수행해 보았다.
이 함수는 별도의 메모리 공간을 생성하지 않고 기존 노드의 메모리 공간을 이용하여 역연결리스트를 구성하기에 효율적인 알고리즘 구조인 것 같다.
생각보다 역 연결리스트를 구성하는 과정이 이해하기 어려웠다.
코드를 봤을 때는 한번에 이해가 되지 않았지만, 그림을 통해 자료구조를 보니 확실히 이해가 빠르게 되었다.
이처럼 다른 복잡한 문제들을 해결하기 위해 그림을 그려서 이해하는 과정도 필요하다는 것을 느꼈다.
함수내에서 Node 구조체 포인터 변수 3개가 while 반복문 속에서 역연결리스트를 구성하기까지 계속 반복한다.
이와 같은 코드를 구현하면서 배열구조에서도 배열의 역을 구하는 코드가 이와 비슷할지 궁금증이 생겼다.
