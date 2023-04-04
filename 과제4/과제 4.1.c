//MyLinkedList.h
#pragma once
#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__

typedef struct Node { //Node 구조체
	int data;
	struct Node* link; //다음 노드의 주소 저장
} Node;
Node* Create_Node(int newData); //노드 생성

void Append_Node(Node** head, Node* newNode); //원형 연결리스트 노드 추가
void Print_Circular_Linked_List(Node* head); //원형 연결리스트 출력
void Append_Node_T(Node** tail, Node* newNode); //tail 기반 원형 연결리스트 노드 추가
void Print_Circular_Linked_List_T(Node* tail); //tail 기반 원형 연결리스트 


//MyLinkedList.c
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

//실습과제 4.1-1
void Append_Node(Node** head, Node* newNode) //원형 연결리스트 노드 추가
{
	if ((*head) == NULL) { //head가 비어있을 경우 head로 newNode 설정
		*head = newNode;
		newNode->link = newNode;
	}
	else { //비어있지 않을 경우
		Node* tail = NULL;
		tail = *head;
    //tail 변수를 이용해 head부터 노드의 끝까지 이동한 후 newNode를 추가하고 newNode와 head 연결
		while (tail->link != *head)
			tail = tail->link;
		tail->link = newNode;
		newNode->link = *head;
	}
}

void Print_Circular_Linked_List(Node* head) //원형 연결리스트 출력
{tai
	if (head == NULL) return; //노드가 비어있을 시 함수 종료
	Node* iter = head;
	int i = 0;
	do { //do while 반복문
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head); //iter 변수가 노드의 head부터 끝까지 돌면서 다시 노드의 head가 될 때까지 반복
	printf("head:%d", iter->data);
	printf("\n");
}

//실습과제 4.1-2
void Append_Node_T(Node** tail, Node* newNode) { //tail 기반 원형 연결리스트 노드 추가
	if ((*tail) == NULL) { //현재 tail이 비어있을 경우 newNode를 tail로 설정
		*tail = newNode;
		newNode->link = newNode;
	}
	else { //newNode와 headNode를 서로 연결하고 현재 tail 노드와 newNode도 연결한 후 tail 위치 변경
		newNode->link = (*tail)->link;
		(*tail)->link = newNode;
		*tail = newNode;
	}
}

void Print_Circular_Linked_List_T(Node* tail) { //tail 기반 원형 연결리스트 출력
	if (tail == NULL) return;
	Node* iter = tail->link;
	int i = 0;
	do {
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != tail->link); //head 노드가 존재하지 않으므로 tail->link로 변경
	printf("head:%d", iter->data);
	printf("\n");
}


//main.c
#include <stdio.h>
#include "MyLinkedList.h"

//실습과제 4.1-1
int main() {
	Node* head = NULL;
  
  //노드 추가
	Append_Node(&head, Create_Node(15));
	Append_Node(&head, Create_Node(25));
	Append_Node(&head, Create_Node(31));
	Append_Node(&head, Create_Node(24));

	Print_Circular_Linked_List(head); //노드 출력

	return 0;
}

//실습과제 4.1-2
int main(void) {
	Node* tail = NULL; //tail 사용

	Append_Node_T(&tail, Create_Node(15));
	Append_Node_T(&tail, Create_Node(25));
	Append_Node_T(&tail, Create_Node(31));
	Append_Node_T(&tail, Create_Node(24));

	Print_Circular_Linked_List_T(tail);
	
	return 0;
}


- 과제에 대한 고찰

단순 연결리스트에서 원형 연결리스트로 변경하여 구현해보았다.
코드는 크게 달라진 것은 없었고 각각의 함수에서 한 두줄 추가되거나 조건문의 조건이 조금 달라진 정도였다.
4.1-1의 코드를 보면, newNode를 추가하는 과정에서 마지막 노드를 찾는 과정에 반복문이 사용되므로 
수행시간은 O(n)이라고 볼 수 있다.
그러나 이와 달리 4.1-2에서는 tail을 사용하여 마지막 노드까지 가는 방법이 아주 간단해졌다. 
수행시간 또한 매우 짧아져 O(1)이다.
자료의 크기가 작을 경우 이 두 가지 방법에서의 실행시간은 큰 차이가 없겠지만, 자료의 크기가 방대해 질경우 
실행시간의 차이가 엄청나게 날 수 있다.
위 두 코드에서 볼 수 있듯이 자료구조에서는 가능한 수행시간과 공간을 줄이는 것이 중요하다고 생각한다.  
