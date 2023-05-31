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


//MyBinaryTee.cpp
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

- 과제에 대한 고찰
연결리스트 자료구조를를 사용한 이진 트리를 구현해보았다.
노드 생성, 소멸시키는 함수와 부모 노드의 왼쪽, 오른쪽 자식의 노드를 만드는 함수를 구현하였으며,
이진트리를 순차적으로 방문하는 순회 알고리즘인 전위, 중위, 후위 알고리즘을 구현했다.
또한 이진트리의 노드의 수와 리프 노드의 수를 구하는 함수를 통하여 이진트리가 올바르게 구현이 됐는지
확인할 수 있었다.
이진트리에서 전위, 중위, 후위 방법으로 트리를 순회하는 함수의 시간복잡도는 이진트리의 크기인 n에 비례
하기에 수행시간은 O(n)이다. 완전이진트리의 경우 마지막 레벨을 제외하고 모든 레벨이 완전히 채워져 있기
때문에 배열을 사용하면 효율적으로 구현할 수 있지만, 이진트리의 경우 연결리스트 자료구조를 활용하는
것이 좀 더 효율적이라는 사실을 알 수 있었다.


