//MyBinaryTree.h
#ifndef __MY_BINARY_TREE_H__
#define __MY_BINARY_TREE_H__
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAX(X, Y) (((X)>(Y))? (X) : (Y))
typedef struct BT_Node {
	int data;
	struct BT_Node* left;
	struct BT_Node* right;
}BT_Node;
BT_Node* BT_Create_Node(int newData);
void BT_Destroy_Node(BT_Node* node);
void BT_Make_Left_Sub_Tree(BT_Node* parent, BT_Node* sub);
void BT_Make_Right_Sub_Tree(BT_Node* parent, BT_Node* sub);
void BT_Preorder_Traversal(BT_Node* node);
void BT_Inorder_Traversal(BT_Node* node);
void BT_Postorder_Traversal(BT_Node* node);
void BT_Count_Node(BT_Node* node, int* count);
void BT_Count_Leaf(BT_Node* node, int* count);
void BT_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height);
void BT_TreePrinter(BT_Node* root);
int BT_Height(BT_Node* root);
#endif


//MyBinaryTRee.cpp
#include <cstdio>
#include <cstdlib>
#include "MyBinaryTree.h"

BT_Node* BT_Create_Node(int newData) { //노드 생성
	BT_Node* newNode = (BT_Node*)malloc(sizeof(BT_Node));
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void BT_Destroy_Node(BT_Node* node) { //노드 소멸
	if (node != NULL)
		free(node);
}
//parent의 왼쪽 자식으로 연결
void BT_Make_Left_Sub_Tree(BT_Node* parent, BT_Node* sub) {
	if (parent->left != NULL)
		BT_Destroy_Node(parent->left);
	parent->left = sub;
}
//parent의 오른쪽 자식으로 연결
void BT_Make_Right_Sub_Tree(BT_Node* parent, BT_Node* sub) {
	if (parent->right != NULL)
		BT_Destroy_Node(parent->right);
	parent->right = sub;
}
void BT_Preorder_Traversal(BT_Node* node) { //전위 순회
	if (node != NULL) {
		printf("%d ", node->data);
		BT_Preorder_Traversal(node->left);
		BT_Preorder_Traversal(node->right);
	}
}
void BT_Inorder_Traversal(BT_Node* node) { //중위 순회
	if (node != NULL) {
		BT_Inorder_Traversal(node->left);
		printf("%d ", node->data);
		BT_Inorder_Traversal(node->right);
	}
}
void BT_Postorder_Traversal(BT_Node* node) { //후위 순회
	if (node != NULL) {
		BT_Postorder_Traversal(node->left);
		BT_Postorder_Traversal(node->right);
		printf("%d ", node->data);
	}
}
void BT_Count_Node(BT_Node* node, int* count) { //노드의 수 계산
	if (node != NULL) {
		*count = *count + 1;
		BT_Count_Node(node->left, count);
		BT_Count_Node(node->right, count);
	}
}
void BT_Count_Leaf(BT_Node* node, int* count) { //리프 노드의 수 계산
	if (node != NULL) {
		BT_Count_Leaf(node->left, count);
		if (node->left == NULL && node->right == NULL)
			*count = *count + 1;
		BT_Count_Leaf(node->right, count);
	}
}

//이진트리 출력 함수
void BT_TreePrinter(BT_Node* root) {
	int h = BT_Height(root);
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
	BT_PrintTree2Matrix(M, root, col / 2, 0, h);
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
int BT_Height(BT_Node* root) {
	if (root == NULL)
		return 0;
	return MAX(BT_Height(root->left), BT_Height(root->right)) + 1;
}
void BT_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height) {
	if (bt_node == NULL) return;
	M[row][col] = bt_node->data;
	BT_PrintTree2Matrix(M, bt_node->left, col - pow(2, height - 2), row + 1, height - 1);
	BT_PrintTree2Matrix(M, bt_node->right, col + pow(2, height - 2), row + 1, height - 1);
}


//main.c
#include <iostream>
#include "MyBinaryTree.h"
using namespace std;

int main()
{
	//노드 생성
	BT_Node* bt_node1 = BT_Create_Node(5);
	BT_Node* bt_node2 = BT_Create_Node(7);
	BT_Node* bt_node3 = BT_Create_Node(6);
	BT_Node* bt_node4 = BT_Create_Node(9);
	BT_Node* bt_node5 = BT_Create_Node(8);
	BT_Node* bt_node6 = BT_Create_Node(2);

	//이진 트리 구성
	BT_Make_Left_Sub_Tree(bt_node1, bt_node2);
	BT_Make_Right_Sub_Tree(bt_node1, bt_node3);
	BT_Make_Left_Sub_Tree(bt_node2, bt_node4);
	BT_Make_Left_Sub_Tree(bt_node3, bt_node5);
	BT_Make_Right_Sub_Tree(bt_node4, bt_node6);

	//이진 트리 출력
	BT_TreePrinter(bt_node1);

	//순회 출력
	printf("Preorder: ");
	BT_Preorder_Traversal(bt_node1); //전위
	printf("\n");
	printf("Inorder: ");
	BT_Inorder_Traversal(bt_node1); //중위
	printf("\n");
	printf("Postorder: ");
	BT_Postorder_Traversal(bt_node1); //후위
	printf("\n");

	//이진 트리의 노드 수를 계산
	int cnt = 0;
	BT_Count_Node(bt_node1, &cnt);
	printf("Total nodes: %d \n", cnt);

	//이진 트리의 리프 노드 수를 계산
	cnt = 0;
	BT_Count_Leaf(bt_node1, &cnt);
	printf("Total leaf nodes: %d \n", cnt);

	return 0;
}
