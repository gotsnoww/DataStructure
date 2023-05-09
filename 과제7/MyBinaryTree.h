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