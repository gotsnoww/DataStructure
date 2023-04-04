#pragma once
#ifndef __MY_LINKED_LIST_H__
#define __MY_LINKED_LIST_H__

typedef struct Node { //Node ����ü
	int data;
	struct Node* link; //���� ����� �ּ� ����
} Node;
Node* Create_Node(int newData); //��� ����
void Destory_Node(Node* node);  //��� �Ҹ�
void Append_Node(Node** head, Node* newNode); //��� �߰�
Node* Get_Node(Node* head, int pos); //��� Ž��
void Remove_Node(Node** head, Node* targetNode); //��� ����
void Insert_Node_After(Node* currentNode, Node* newNode); //��� ����
void Print_Circular_Linked_List(Node* head); //���Ḯ��Ʈ ��� �Լ�
Node* Reverse_List(Node* head); //�� ���Ḯ��Ʈ ���� �Լ�

void Append_Node_T(Node** tail, Node* newNode);
void Print_Circular_Linked_List_T(Node* tail);

#endif