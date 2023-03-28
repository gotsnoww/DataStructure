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