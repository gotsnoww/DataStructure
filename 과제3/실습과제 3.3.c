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
Node* Reverse_List(Node* head); //역 연결리스트 구성 함수

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

//연결리스트의 역 연결리스트를 구성하는 함수
Node* Reverse_List(Node* head)
{
	Node* p = head;
	Node* q = NULL;
	Node* r;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

//
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
