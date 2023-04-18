//MyOoublyLinkedList.h
#ifndef __MY_DOUBLY_LINKED_LIST_H__
#define __MY_DOUBLY_LINKED_LIST_H__
typedef struct Node { //Node 구조체
	int data; //데이터 필드
	struct Node* prev;// 다음 노드의 주소를 저장
	struct Node* next;// 다음 노드의 주소를 저장
}Node;
Node* DLL_Create_Node(int newData); //노드 생성
void DLL_Destroy_Node(Node* node); //노드 소멸
void DLL_Append_Node(Node** head, Node* newNode); //노드 추가
Node* DLL_Get_Node(Node* head, int pos); //노드 탐색
void DLL_Remove_Node(Node** head, Node* targetNode); //노드 삭제
void DLL_Insert_Node_After(Node* currentNode, Node* newNode); //노드 삽입
void DLL_Print_Linked_List(Node* head); //이중 연결리스트 출력
void DLL_Print_Linked_List_Reverse(Node* tail);//이중 연결리스트 역순 출력
#endif


//MyOoublyLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include "MyDoublyLinkedList.h"

Node* DLL_Create_Node(int newData) //노드 생성
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}
void DLL_Destroy_Node(Node* node) //노드 소멸
{
	if (node != NULL)
		free(node);
}
void DLL_Append_Node(Node** head, Node* newNode) //노드 추가
{
	Node* tail = NULL;

	if ((*head) == NULL)
		*head = newNode;
	else {
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = newNode;
		newNode->prev = tail;
	}
}
Node* DLL_Get_Node(Node* head, int pos) //노드 탐색
{
	Node* temp = head;
	for (int i = 0; i < pos; i++)
		temp = temp->next;

	return temp;
}
void DLL_Remove_Node(Node** head, Node* targetNode) //노드 삭제
{
	Node* temp = *head;

	if (targetNode != *head) { //targetNode가 head 노드가 아닐경우
		while (temp->next != targetNode) //targetNode의 이전 노드를 찾아 temp에 저장
			temp = temp->next;

		if (targetNode->next != NULL) { 
			temp->next = targetNode->next; //targetNode의 이전과 이후 노드를 서로 연결
			temp->next->prev = temp;
		}
		else //targetNode가 tail 노드일 경우
			temp->next = NULL;
	}
	else //targetNode가 head 노드일 경우
	{
		*head = (*head)->next; //head 노드를 다음 노드로 변경

		if(*head != NULL) //head 노드가 NULL이 아닐 경우에만 (NULL의 prev가 존재할 수 없음)
			(*head)->prev = NULL;
	}

	DLL_Destroy_Node(targetNode); //targetNode 소멸
}
void DLL_Insert_Node_After(Node* currentNode, Node* newNode) //노드 삽입
{
	newNode->next = currentNode->next;
	currentNode->next->prev = newNode;
	newNode->prev = currentNode;
	currentNode->next = newNode;
}
void DLL_Print_Linked_List(Node* head) //이중 연결리스트 출력
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL) {
		printf("N[%d]:%d", i, iter->data);
		iter = iter->next;
		if (iter != NULL) printf(" <-> ");
		i++;
	}
	printf("\n");
}
void DLL_Print_Linked_List_Reverse(Node* tail) //이중 연결리스트 역순 출력
{
	Node* iter = tail;
	int i = 0;
	while (iter != NULL) {
		printf("N[%d]:%d", i, iter->data);
		iter = iter->prev;
		if (iter != NULL) printf(" <-> ");
		i++;
	}
	printf("\n");
}


//main.c
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



- 과제에 대한 고찰

과제를 통해 이중 연결리스트(양방향 연결리스트)를 구현하여 보았다.
기존의 단방향 연결리스트는 현재 노드에 후속 노드만이 연결되어있는 구조였지만,
양방향 연결리스트는 노드에 선행 노드와 후속 노드 양 쪽으로 연결이 되어 있는 구조이다.
그렇기에 양방향 연결리스트는 자료 내의 특정한 값을 찾을 때 현재 노드의 앞 뒤 모두 이동이 가능하여
단방향 연결리스트에 비해 보다 효율적으로 작업을 수행할 수 있다.
하지만 양방향 연결리스트는 단방향 연결리스트에 비해 메모리 공간을 더 많이 사용한다는 단점이 있다.
	
과제를 해결하는데 있어서 생각보다 까다로웠던 것은 Remove 함수를 구현하는 것이었다.
이중 연결리스트 내의 특정한 노드를 지우는 함수인데, 지우고 싶은 노드의 위치에 따라 고려해야할 사항이 생긴다.
head 노드일 경우와 tail 노드일 경우, 그리고 중간에 끼여있는 노드일 경우 3가지로 나눌 수 있는데
중간 노드의 경우 해당 노드의 이전과 이후 노드를 서로 연결시킨 후 소멸시키면 되지만 tail노드이거나 head 노드이면
NULL값을 설정해줘야 하고 연결리스트가 비었을 경우의 조건도 생각해줘야 해서 구현하기 쉽지 않았다.
그래도 디버깅과 수차례의 코드 수정 끝에 원하던 모습의 코드를 짤 수 있었다.
	
