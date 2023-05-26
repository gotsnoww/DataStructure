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
		printf("�ߺ�!!!\n");
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

void Delete(Tree* tree, int data) { //����: �� 4���� ���
	//�����ϰ��� �ϴ� ���� ���� ��� - search �Լ� Ȱ��
		

	// �����ϰ��� �� ����� �ڽ��� ���� ���
	if (tree->cur->Lnode == NULL && tree->cur->Rnode == NULL) {
		Ch_No(tree);
	}

	//�����ϰ��� �� ����� �ڽ��� �ϳ��� �ִ� ���
	else if (tree->cur->Lnode == NULL || tree->cur->Rnode == NULL) {
		Ch_One(tree);
	}

	//�����ϰ��� �� ����� �ڽ��� ���ΰ��
	else if (tree->cur->Lnode != NULL && tree->cur->Rnode != NULL) {
		Ch_Two(tree);
	}
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
����

�ڽĳ�尡 0���� ���
����Ž��Ʈ������ ��尡 �ϳ��� �������� ���(��Ʈ���)

�ڽĳ�尡 1���� ���
��Ʈ��尡 �ڽĳ�� 1���� ������ ���� ��� ��Ʈ��� ����?

����Լ�
*/