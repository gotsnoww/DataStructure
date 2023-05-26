#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* Lnode;
	struct Node* Rnode;
}Node;

typedef struct tree {
	Node* root;
	Node* cur;
	Node* parent;
	Node* child;
}Tree;

int Search(Tree* tree, int data) {
	tree->cur = tree->root;
	tree->parent = NULL;

	while (1) {
		if (tree->cur->key == data) {
			return 1;
		}
		else if (tree->cur->key < data) {
			tree->parent = tree->cur;
			if (tree->cur->Rnode == NULL) {
				return 0;
			}
			tree->cur = tree->cur->Rnode;
		}
		else if (tree->cur->key > data) {
			tree->parent = tree->cur;
			if (tree->cur->Lnode == NULL) {
				return 0;
			}
			tree->cur = tree->cur->Lnode;
		}
	}
}

void Insert(Tree* tree, int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = data;
	newnode->Lnode = NULL;
	newnode->Rnode = NULL;

	if (tree->root == NULL) {
		tree->root = newnode;
		return;
	}

	if (Search(tree, data)) {
		printf("중복!!!\n");
		return;
	}
	else {
		if (tree->parent->key < data) {
			tree->parent->Rnode = newnode;
		}
		else {
			tree->parent->Lnode = newnode;
		}
	}
}

void Display(Node* root) {
	if (root != NULL) {
		Display(root->Lnode);
		printf("%d -> ", root->key);
		Display(root->Rnode);
	}
}

void Delete(Tree* tree, int data) { //과제: 총 4가지 경우
	//삭제하고자 하는 값이 없는 경우
	if (Search(tree, data) == 0) {
		printf("삭제하고자 하는 값이 없습니다!!\n");
	}	

	// 삭제하고자 할 노드의 자식이 없는 경우
	if (tree->cur->Lnode == NULL && tree->cur->Rnode == NULL) {
		Ch_No(tree);
	}

	//삭제하고자 할 노드의 자식이 하나만 있는 경우
	else if (tree->cur->Lnode == NULL || tree->cur->Rnode == NULL) {
		Ch_One(tree);
	}

	//삭제하고자 할 노드의 자식이 둘인경우
	else if (tree->cur->Lnode != NULL && tree->cur->Rnode != NULL) {
		Ch_Two(tree);
	}
}

void Ch_No(Tree* tree) {

}
void Ch_One(Tree* tree) {

}
void Ch_Two(Tree* tree) {

}

void main() {
	Tree tree;
	tree.root = NULL;
	tree.cur = NULL;
	tree.parent = NULL;
	tree.child = NULL;

	Insert(&tree, 15);
	Insert(&tree, 18);
	Insert(&tree, 10);
	Insert(&tree, 100);
	Insert(&tree, 19);
	Insert(&tree, 11);
	Insert(&tree, 1);
	Insert(&tree, 16);
	Insert(&tree, 4);
	Insert(&tree, 8);
	Insert(&tree, 3);
	Insert(&tree, 9);

	Display(tree.root);

	Delete(&tree, 10);
}

/*
삭제

자식노드가 0개인 경우
이진탐색트리에서 노드가 하나만 남아있을 경우(루트노드)

자식노드가 1개인 경우
루트노드가 자식노드 1개를 가지고 있을 경우 루트노드 삭제?

재귀함수
*/
