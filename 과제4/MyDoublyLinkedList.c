#include <stdio.h>
#include <stdlib.h>
#include "MyDoublyLinkedList.h"

Node* DLL_Create_Node(int newData) //��� ����
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void DLL_Destroy_Node(Node* node) //��� �Ҹ�
{
	if (node != NULL)
		free(node);
}

void DLL_Append_Node(Node** head, Node* newNode) //��� �߰�
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

Node* DLL_Get_Node(Node* head, int pos) //��� Ž��
{
	Node* temp = head;
	for (int i = 0; i < pos; i++)
		temp = temp->next;

	return temp;
}

void DLL_Remove_Node(Node** head, Node* targetNode) //��� ����
{
	Node* temp = *head;

	if (targetNode != *head) { //targetNode�� head ��尡 �ƴҰ��
		while (temp->next != targetNode) //targetNode�� ���� ��带 ã�� temp�� ����
			temp = temp->next;

		if (targetNode->next != NULL) {
			temp->next = targetNode->next; //targetNode�� ������ ���� ��带 ���� ����
			temp->next->prev = temp;
		}
		else
			temp->next = NULL;
	}
	else //targetNode�� head ����� ���
	{
		*head = (*head)->next; //head ��带 ���� ���� ����

		if(*head != NULL) //head ��尡 NULL�� �ƴ� ��쿡�� (NULL�� prev�� ������ �� ����)
			(*head)->prev = NULL;
	}

	DLL_Destroy_Node(targetNode); //targetNode �Ҹ�
}

void DLL_Insert_Node_After(Node* currentNode, Node* newNode) //��� ����
{
	newNode->next = currentNode->next;
	currentNode->next->prev = newNode;
	newNode->prev = currentNode;
	currentNode->next = newNode;
}

void DLL_Print_Linked_List(Node* head) //���� ���Ḯ��Ʈ ���
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

void DLL_Print_Linked_List_Reverse(Node* tail) //���� ���Ḯ��Ʈ ���� ���
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