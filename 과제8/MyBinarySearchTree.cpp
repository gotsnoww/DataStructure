#include "MyBinarySearchTree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

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

//BST 관련 함수
int BST_Min(BT_Node* root) {
	if (root == NULL)
		exit(1);
	BT_Node* iter = root;
	while (iter->left != NULL)
		iter = iter->left;

	return iter->data;
}
int BST_Max(BT_Node* root) {
	if (root == NULL)
		exit(1);
	BT_Node* iter = root;
	while (iter->right != NULL)
		iter = iter->right;

	return iter->data;
}
BT_Node* BST_Search(BT_Node* root, int target) {
	if (root == NULL)
		return NULL;
	if (target == root->data)
		return root;
	if (target < root->data) //재귀 방식
		return BST_Search(root->left, target);
	else
		return BST_Search(root->left, target);
}
void BST_Insert(BT_Node** root, int key) {
	BT_Node* newNode = BST_Create_Node(key);
	if (*root == NULL) {
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
void BST_Delete(BT_Node** root, int key) {
	BT_Node* vRoot = (BT_Node*)malloc(sizeof(BT_Node));
	vRoot->right = *root;
	BT_Node* iter = *root;
	BT_Node* parent = vRoot;
	while (iter != NULL && iter->data != key) {
		parent = iter;
		if (key < iter->data)
			iter = iter->left;
		else
			iter = iter->right;
	}
	if (iter == NULL)
		exit(1);
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
			delNode->data = successor->data; //대체 노드의 키 값을 복사
		}
		if (pSuccessor->left = successor)
			pSuccessor->left = successor->right;
		else
			pSuccessor->right = successor->right;
		delNode = successor;
	}
	if (vRoot->right != *root){ //루트노드가 변경되었다면, 새로운 루트노드 정보를 업데이트
		*root = vRoot->right;
		BST_Destroy_Node(vRoot);
		BST_Destroy_Node(delNode);
	}
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
