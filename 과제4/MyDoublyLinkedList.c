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
		else
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