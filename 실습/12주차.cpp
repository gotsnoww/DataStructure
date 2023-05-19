#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* L;
	struct node* R;
}Node;

Node* Cre(int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->L = NULL;
	newnode->R = NULL;

	return newnode;
}

void Preorder(Node* root) {
	if (root == NULL) {
		return;
	}

	printf("%d -> ", root->data);
	Preorder(root->L);
	Preorder(root->R);
}
void Inorder(Node* root) {
	if (root == NULL) {
		return;
	}

	Inorder(root->L);
	printf("%d -> ", root->data);
	Inorder(root->R);
}
void Postorder(Node* root) {
	if (root == NULL) {
		return;
	}

	Postorder(root->L);
	Postorder(root->R);
	printf("%d -> ", root->data);
}
void main() {
	Node* tree[8];
	
	for (int i = 0; i < 8; i++) {
		tree[i] = Cre(i);
	}

	tree[0]->L = tree[1];
	tree[0]->R = tree[5];
	tree[1]->L = tree[2];
	tree[5]->R = tree[6];
	tree[2]->L = tree[3];
	tree[6]->R = tree[7];
	tree[3]->R = tree[4];

	printf("\n전위 : ");
	Preorder(tree[0]);
	printf("\n중위 : ");
	Inorder(tree[0]);
	printf("\n후위 : ");
	Postorder(tree[0]);
}
