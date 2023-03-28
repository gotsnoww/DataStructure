#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"

Node* Create_Node(int newData) //��� ����
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->link = NULL;
	return newNode;
}

void Destory_Node(Node* node) //��� �Ҹ�
{
	if (node != NULL)
		free(node);
}

void Append_Node(Node** head, Node* newNode) //��� �߰�
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

Node* Get_Node(Node* head, int pos) //��� Ž��
{
	Node* temp = head;
	for (int i = 0; i < pos; i++)
		temp = temp->link;

	return temp;
}

//������ ��ġ�� �ִ� ��带 �����ϴ� �Լ�
void Remove_Node(Node** head, Node* targetNode)
{
	Node* temp = *head;

	if (targetNode != *head) { //targetNode�� head ��尡 �ƴҰ��
		while (temp->link != targetNode) //targetNode�� ���� ��带 ã�� temp�� ����
			temp = temp->link;

		temp->link = targetNode->link; //targetNode�� ������ ���� ��带 ���� ����
	}
	else //targetNode�� head ����� ���
		*head = (*head)->link; //head ��带 ���� ���� ����

	Destory_Node(targetNode); //targetNode �Ҹ�
}

//������ ��ġ�� ���ο� ��带 �����ϴ� �Լ�
void Insert_Node_After(Node* currentNode, Node* newNode)
{
	newNode->link = currentNode->link;
	currentNode->link = newNode;
}

void Print_Linked_List(Node* head) //���Ḯ��Ʈ ��� �Լ�
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