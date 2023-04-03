#include <stdio.h>
#include <stdlib.h>

typedef struct Node { //Node 구조체
	int data;
	struct Node* link; //다음 노드의 주소 저장
} Node;

Node* Create_Node(int newData);
void Destory_Node(Node* node);
void Append_Node(Node** head, Node* newNode);
void Print_Linked_List(Node* head);

int main() {
	Node* head = NULL;
	Node* newNode = NULL;

	newNode = Create_Node(15); //15노드 생성
	Append_Node(&head, newNode); //추가

	newNode = Create_Node(31); //31노드 생성
	Append_Node(&head, newNode); //추가

	Print_Linked_List(head); //연결리스트 출력

	return 0;
}

//노드를 생성하는 함수
Node* Create_Node(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->link = NULL;
	return newNode;
}

//노드를 삭제하는 함수
void Destory_Node(Node* node) {
	if (node != NULL)
		free(node);
}

//연결리스트의 제일 뒷부분에 새로운 노드를 추가하는 함수
void Append_Node(Node** head, Node* newNode) {
	if ((*head) == NULL) //head가 비어있을 경우 newNode를 헤드로 설정
		*head = newNode;
	else { //비어 있지 않을 경우 제일 끝 부분에 newNode 추가
		Node* tail = NULL;
		tail = *head;
		while (tail->link != NULL)
			tail = tail->link;
		tail->link = newNode;
	}
}

//연결리스트를 출력하는 함수
void Print_Linked_List(Node* head) {
	Node* iter = head;
	int i = 0;
	while (iter != NULL) { //노드의 값이 NULL이 아닐 때 까지 다음 노드로 이동하며 출력
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");
}


- 과제에 대한 고찰
연결리스트라는 자료구조에 대해 배우고 코드를 구현해보았다.
기존에 알고있던 배열과는 다르게 배열이 가진 여러 단점들을 상쇄하고 수많은 장점을 가진다는 것을 알게 되었다.
노드를 생성, 삭제하는 함수를 구현하는 과정은 큰 어려움이 없었다.
노드를 추가하는 함수를 구현할 때 처음 노드 하나만 있을 때는 head노드가 NULL로 설정되어 있으므로 if 조건문을 통해 head값을 설정하도록 구현했다.
노드를 출력하는 함수는 while 반복문을 사용하여 노드의 head부터 끝까지 모든 값을 출력하도록 구현했다.
이렇게 직접 함수들을 구현해보면서 어느정도 연결리스트의 기본 개념을 이해할 수 있었던 것 같다.
