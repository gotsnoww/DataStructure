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

// ���� Append_Node
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

/*�ǽ����� 4.1 - 1 Append_Node
void Append_Node(Node** head, Node* newNode) //��� �߰�
{
	if ((*head) == NULL) {
		*head = newNode;
		newNode->link = newNode;
	}
	else {
		Node* tail = NULL;
		tail = *head;
		while (tail->link != *head)
			tail = tail->link;
		tail->link = newNode;
		newNode->link = *head;
	}
} */

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

void Print_Circular_Linked_List(Node* head) //���Ḯ��Ʈ ��� �Լ�
{
	if (head == NULL) return;
	Node* iter = head;
	int i = 0;
	do {
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != head);
	printf("head:%d", iter->data);
	printf("\n");
}

//���Ḯ��Ʈ�� �� ���Ḯ��Ʈ�� �����ϴ� �Լ�
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


//�ǽ����� 4.1-2
void Append_Node_T(Node** tail, Node* newNode) {
	if ((*tail) == NULL) {
		*tail = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = (*tail)->link;
		(*tail)->link = newNode;
		*tail = newNode;
	}
}

void Print_Circular_Linked_List_T(Node* tail) {
	if (tail == NULL) return;
	Node* iter = tail->link;
	int i = 0;
	do {
		printf("node[%d]:%d", i, iter->data);
		iter = iter->link;
		if (iter != NULL) printf(" -> ");
		i++;
	} while (iter != tail->link);
	printf("head:%d", iter->data);
	printf("\n");
}

//�ǽ����� 4.2
Node* Merge_List(Node* head_a, Node* head_b) {
	Node* head_c = NULL;

	while (head_a != NULL && head_b != NULL) {
		if (head_a->data < head_b->data) {
			Append_Node(&head_c, Create_Node(head_a->data));
			head_a = head_a->link;
		}
		else {
			Append_Node(&head_c, Create_Node(head_b->data));
			head_b = head_b->link;
		}
	}

	//���Ḯ��Ʈ a�� �ܿ��� ó��
	while (head_a != NULL)
	{
		Append_Node(&head_c, Create_Node(head_a->data));
		head_a = head_a->link;
	}
	//���Ḯ��Ʈ b�� �ܿ��� ó��
	while (head_a != NULL)
	{
		Append_Node(&head_c, Create_Node(head_b->data));
		head_b = head_b->link;
	}

	return head_c;
}