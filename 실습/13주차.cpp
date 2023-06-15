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

void Ch_No(Tree* tree) {
	if (tree->parent == NULL) {
		// 삭제할 노드가 루트 노드인 경우
		tree->root = NULL;
	}
	else if (tree->parent->Lnode == tree->cur) {
		tree->parent->Lnode = NULL;
	}
	else {
		tree->parent->Rnode = NULL;
	}
}
void Ch_One(Tree* tree) {
	if (tree->cur->Lnode == NULL)
		tree->child = tree->cur->Rnode;
	else
		tree->child = tree->cur->Lnode;

	if (tree->parent->Lnode == tree->cur)
		tree->parent->Lnode = tree->child;
	else
		tree->parent->Rnode = tree->child;
}
void Ch_Two(Tree* tree) {
	//삭제할 노드의 오른쪽 서브트리 탐색
	Node* delnode = tree->cur;
	tree->cur = tree->cur->Rnode;

	while (tree->cur->Lnode != NULL) {
		tree->parent = tree->cur;
		tree->cur = tree->cur->Lnode;
	}
	delnode->key = tree->cur->key;

	if (tree->parent != NULL) { //삭제할 노드가 루트노드가 아닐 경우
		if (tree->parent->Lnode == tree->cur)
			tree->parent->Lnode = tree->cur->Rnode;
		else
			tree->parent->Rnode = tree->cur->Rnode;
	}
}

void Delete(Tree* tree, int data) { //과제: 총 4가지 경우
	//삭제하고자 하는 값이 없는 경우
	if (Search(tree, data) == 0) {
		printf("삭제하고자 하는 값이 없습니다!!\n");
		return;
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

	Node* temp = tree->cur; // 삭제된 노드의 주소를 임시로 저장
	tree->cur = NULL; // tree->cur을 NULL로 초기화
	free(temp); // 임시로 저장한 주소의 노드를 해제}
}

void main() {
	Tree tree;
	tree.root = NULL;
	tree.cur = NULL;
	tree.parent = NULL;
	tree.child = NULL;

	Insert(&tree, 50);
	Insert(&tree, 35);
	Insert(&tree, 70);
	Insert(&tree, 6);
	Insert(&tree, 40);
	Insert(&tree, 36);
	Insert(&tree, 45);
	Insert(&tree, 38);
	Insert(&tree, 37);

	Display(tree.root);
	printf("\n");
	Delete(&tree, 50);
	Display(tree.root);
}
