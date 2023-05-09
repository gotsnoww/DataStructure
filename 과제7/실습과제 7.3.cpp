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