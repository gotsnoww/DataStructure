//MyLinkdedList.h
#pragma once
#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__

typedef struct Node { //Node 구조체
	int data;
	struct Node* link; //다음 노드의 주소 저장
} Node;
Node* Create_Node(int newData); //노드 생성
void Destory_Node(Node* node);  //노드 소멸
void Append_Node(Node** head, Node* newNode); //노드 추가
Node* Get_Node(Node* head, int pos); //노드 탐색
void Remove_Node(Node** head, Node* targetNode); //노드 삭제
void Insert_Node_After(Node* currentNode, Node* newNode); //노드 삽입
void Print_Linked_List(Node* head); //연결리스트 출력 함수

#endif


//MyLinkdedList.c
#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"

Node* Create_Node(int newData) //노드 생성
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->link = NULL;
	return newNode;
}

void Destory_Node(Node* node) //노드 소멸
{
	if (node != NULL)
		free(node);
}

void Append_Node(Node** head, Node* newNode) //노드 추가
{
	if ((*head) == NULL)
		*head = newNode;
	else {
		Node* tail = NULL;
		tail = *head;
		while (tail->link != NULL)
			tail = tail->link;
		tail->link = newNode;
	}
}

Node* Get_Node(Node* head, int pos) //노드 탐색
{
	Node* temp = head;
	for (int i = 0; i < pos; i++)
		temp = temp->link;

	return temp;
}

//임의의 위치에 있는 노드를 삭제하는 함수
void Remove_Node(Node** head, Node* targetNode)
{
	Node* temp = *head;

	if (targetNode != *head) { //targetNode가 head 노드가 아닐경우
		while (temp->link != targetNode) //targetNode의 이전 노드를 찾아 temp에 저장
			temp = temp->link;

		temp->link = targetNode->link; //targetNode의 이전과 이후 노드를 서로 연결
	}
	else //targetNode가 head 노드일 경우
		*head = (*head)->link; //head 노드를 다음 노드로 변경

	Destory_Node(targetNode); //targetNode 소멸
}

//임의의 위치에 새로운 노드를 삽입하는 함수
void Insert_Node_After(Node* currentNode, Node* newNode)
{
	newNode->link = currentNode->link;
	currentNode->link = newNode;
}

void Print_Linked_List(Node* head) //연결리스트 출력 함수
{
	Node* iter = head;
	int i = 0;
	while (iter != NULL) {
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	}
	printf("\n");
}


//main.c
#include <stdio.h>
#include "MyLinkedList.h"

int main() {
	Node* head = NULL;
	//기본 노드 생성
	Append_Node(&head, Create_Node(15));
	Append_Node(&head, Create_Node(31));
	Print_Linked_List(head);

	//Get_Node() 함수 기능 테스트
	Node* temp = Get_Node(head, 0);
	printf("Get_Node() test: %d\n", temp->data);

	//Insert_Node_After() 함수 기능 테스트
	Insert_Node_After(Get_Node(head, 0), Create_Node(25));
	Print_Linked_List(head);

	//Remove_Node() 함수 기능 테스트
	Remove_Node(&head, Get_Node(head, 0));
	Print_Linked_List(head);

	return 0;
}


- 과제에 대한 고찰
이전 과제의 연결리스트의 기능들과 이번 과제로 추가한 기능들을 구현하여 연결리스트가 동작하도록 코드를 짜보았다.
연결리스트의 함수들은 모두 MyLinkedList라는 헤더파일과 c파일에 구현되어 있다.
기존 연결리스트에는 노드의 제일 뒷 부분에 노드를 추가하는 기능만을 가졌었는데, 이번에는 임의의 위치 값을 함수의 인자로 받아서 
해당 위치에 노드를 추가하거나 삭제할 수 있는 기능을 가진다.
새로운 기능들을 추가하면서 특정 위치에 있는 노드를 삭제하는 코드를 구현하는 코드가 생각보다 복잡했다. 
노드를 삭제했을 때 이전 노드와 이후 노드를 서로 연결시켜줘야 하는데 이 때 삭제할 노드가 head 노드이냐 아니냐에 따라 내용이 달라지기에 이를 조건문으로 나누어보았다.
이 외의 기능들은 간단히 구현할 수 있었다.
과제를 수행해보면서 느낀 것이 어떠한 자료들을 정리하고 관리할 때는 확실히 배열보다는 이러한 자료구조가 좋은 것 같다.
자료구조를 어느 곳에 사용해야 좋은지는 아직 잘 알지 못 하지만 추후에 사용해야 할 곳이 있을 때 굉장히 도움이 될 것 같다.
