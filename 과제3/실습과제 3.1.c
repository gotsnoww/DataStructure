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
