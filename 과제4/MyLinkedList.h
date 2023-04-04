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
void Print_Circular_Linked_List(Node* head); //연결리스트 출력 함수
Node* Reverse_List(Node* head); //역 연결리스트 구현 함수

void Append_Node_T(Node** tail, Node* newNode);
void Print_Circular_Linked_List_T(Node* tail);

#endif