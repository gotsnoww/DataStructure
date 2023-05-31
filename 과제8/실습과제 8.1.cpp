//MyBinarySearchTree.h
#pragma once
#ifndef __MY_BINARY_SEARCH_TREE_H__
#define __MY_BINARY_SEARCH_TREE_H__
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAX(X, Y) (((X)>(Y))? (X) : (Y))

typedef struct BT_Node { //연결리스트 자료구조
	int data;
	struct BT_Node* left;
	struct BT_Node* right;
}BT_Node;

BT_Node* BST_Create_Node(int newData);
void BST_Destroy_Node(BT_Node* node);

//BST 관련 함수
int BST_Min(BT_Node* root);
int BST_Max(BT_Node* root);
BT_Node* BST_Search(BT_Node* root, int target);
void BST_Insert(BT_Node** root, int key);
void BST_Delete(BT_Node** root, int key);

//출력 관련 함수
void BST_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height);
void BST_TreePrinter(BT_Node* root);
int BST_Height(BT_Node* root);
#endif


//MyBinarySearchTree.cpp
#include "MyBinarySearchTree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

BT_Node* BST_Create_Node(int newData) { //노드 생성
	BT_Node* newNode = (BT_Node*)malloc(sizeof(BT_Node));
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void BST_Destroy_Node(BT_Node* node) { //노드 소멸
	if (node != NULL)
		free(node);
}

//BST 관련 함수
int BST_Min(BT_Node* root) { //가장 작은 값 탐색
	if (root == NULL)
		exit(1);
	BT_Node* iter = root;
	while (iter->left != NULL)
		iter = iter->left;

	return iter->data;
}
int BST_Max(BT_Node* root) { //가장 큰 값 탐색
	if (root == NULL)
		exit(1);
	BT_Node* iter = root;
	while (iter->right != NULL)
		iter = iter->right;

	return iter->data;
}
//주어진 target(key 값)을 가진 노드 탐색
BT_Node* BST_Search(BT_Node* root, int target) {
	if (root == NULL)
		return NULL;
	if (target == root->data)
		return root;
	if (target < root->data) //재귀 방식
		return BST_Search(root->left, target);
	else
		return BST_Search(root->right, target);
}
void BST_Insert(BT_Node** root, int key) { //새로운 키 값을 삽입
	BT_Node* newNode = BST_Create_Node(key);
	if (*root == NULL) { //루트 노드가 비어있을 경우
		*root = newNode;
	}
	else {
		BT_Node* parent = NULL;
		BT_Node* iter = *root;
		while (iter != NULL) {
			parent = iter;
			if (key == iter->data) return; //중복값 허용 X
			if (key < iter->data) 
				iter = iter->left;
			else 
				iter = iter->right;
		}
		if (key < parent->data)
			parent->left = newNode;
		else
			parent->right = newNode;
	}

}
void BST_Delete(BT_Node** root, int key) { //주어진 키 값을 삭제
	BT_Node* vRoot = (BT_Node*)malloc(sizeof(BT_Node)); //가상 노드 생성
	vRoot->right = *root; //가상의 노드를 루트 노드로 설정
	BT_Node* iter = *root; //반복자
	BT_Node* parent = vRoot; //부모 노드
	while (iter != NULL && iter->data != key) {
		parent = iter;
		if (key < iter->data)
			iter = iter->left;
		else
			iter = iter->right;
	}
	if (iter == NULL) //삭제할 노드 발견 X
		exit(1); //종료
	BT_Node* delNode = iter;

	//case 1: 단말 노드 삭제
	if (delNode->left == NULL && delNode->right == NULL) {
		if (parent->left == delNode)
			parent->left = NULL;
		else
			parent->right = NULL;
	}

	//case 2: 하나의 서브 트리를 가지는 노드를 삭제
	else if (delNode->left == NULL || delNode->right == NULL) {
		BT_Node* child = NULL;
		if (delNode->left == NULL)
			child = delNode->right;
		else
			child = delNode->left;
		if (parent->left == delNode)
			parent->left = child;
		else
			parent->right = child;
	}
	//case 3: 두 개의 서브 트리를 가지는 노드를 삭제
	else {
		BT_Node* successor = NULL;
		BT_Node* pSuccessor = NULL;
		successor = delNode->right; //대체 노드 저장
		pSuccessor = delNode; //대체 노드의 부모 노드 저장
		while (successor->left != NULL) {
			pSuccessor = successor;
			successor = successor->left; //왼쪽 서브트리로 이동
		}
		delNode->data = successor->data; //대체 노드의 키 값을 복사
		if (pSuccessor->left == successor)
			pSuccessor->left = successor->right;
		else
			pSuccessor->right = successor->right;
		delNode = successor;
	}
	
	//루트노드가 변경되었다면, 새로운 루트노드 정보를 업데이트
	if (vRoot->right != *root) /
		*root = vRoot->right;
	BST_Destroy_Node(vRoot);
	BST_Destroy_Node(delNode);
}

//출력 관련 함수
void BST_TreePrinter(BT_Node* root) {
	int h = BST_Height(root);
	int col = (1 << h) - 1;
	int** M = new int* [h];
	for (int i = 0; i < h; i++) {
		M[i] = new int[col];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
	BST_PrintTree2Matrix(M, root, col / 2, 0, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j] == 0)
				printf(" ");
			else
				printf("%2d", M[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
}
int BST_Height(BT_Node* root) {
	if (root == NULL)
		return 0;
	return MAX(BST_Height(root->left), BST_Height(root->right)) + 1;
}
void BST_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height) {
	if (bt_node == NULL) return;
	M[row][col] = bt_node->data;
	BST_PrintTree2Matrix(M, bt_node->left, col - pow(2, height - 2), row + 1, height - 1);
	BST_PrintTree2Matrix(M, bt_node->right, col + pow(2, height - 2), row + 1, height - 1);
}


//main.c
#include <iostream>
#include "MyBinarySearchTree.h" 

int main(){ 
	BT_Node* root = NULL; 

	//이진 탐색 트리 구성 
	BST_Insert(&root, 50); 
	BST_Insert(&root, 35); 
	BST_Insert(&root, 70); 
	BST_Insert(&root, 6); 
	BST_Insert(&root, 40); 
	BST_Insert(&root, 36); 
	BST_Insert(&root, 45); 
	BST_Insert(&root, 38); 
	BST_Insert(&root, 37);
	BST_TreePrinter(root);

	//기본 연산 기능 테스트 
	printf("Min value: %d \n", BST_Min(root)); 
	printf("Max value: %d \n", BST_Max(root)); 
	printf("Search 36 node: %d \n", BST_Search(root, 36)->data); 
	//삭제 테스트 B
	BST_Delete(&root, 50); //35, 38, 6, 50 노드 삭제 테스트 진행
	BST_Insert(&root, 39); 
	BST_TreePrinter(root); 

	return 0; 
}


- 과제에 대한 고찰
연결리스트 자료구조를 활용하여 이진 트리를 구현하고 이진 탐색 트리에서 키 값을
삽입, 삭제, 탐색하는 함수를 구현하였다. 또한 이진 탐색 트리를 순회하면서 가장 작은
키 값을 가진 노드와 가장 큰 키 값을 가진 노드를 찾아내는 함수를 구현하였다.
이진 탐색 트리에서 노드를 삭제하는 함수를 제외하고는 모두 구현이 어렵지 않았다.
이진 트리 노드의 키 값을 삭제하는 함수를 구현할 때 해당 노드가 가진 서브트리를 고려하여
구현해야 했기에 이를 case 3개로 나누어 구현하였다. 삭제할 노드가 자식노드를 아예 가지지
않는 단말 노드일 경우와 하나의 서브 트리, 두 개의 서브 트리를 가질 경우로 case를 나누었는데
이 중에서도 세 번째 case인 삭제할 대상 노드가 두 개의 서브 트리를 가질 경우 생각해야 할 조건이
너무 많아서 구현이 쉽지 않았다.
이렇게 구현된 이진 탐색 트리의 수행시간은 이진 트리의 높이에 비례하기 때문에, 수행시간은 한 번에
수행되는 O(n)부터 최악의 경우인 O(log n)까지 가능하다.  
