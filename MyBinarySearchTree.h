#pragma once
#ifndef __MY_BINARY_SEARCH_TREE_H__
#define __MY_BINARY_SEARCH_TREE_H__
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAX(X, Y) (((X)>(Y))? (X) : (Y))

typedef struct BT_Node {
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