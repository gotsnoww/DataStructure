/* 
#include <stdio.h>
#include <stdlib.h>

//원형 연결리스트
typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct list {
	Node* tail;
	Node* cur;
	Node* bef;
}List;

void Insert(List* list, int val) {
	Node* newnode = malloc(sizeof(Node));
	newnode->data = val;
	newnode->link = NULL;

	if (list->tail == NULL) {
		list->tail = newnode;
		newnode->link = newnode;
	}
	else {
		newnode->link = list->tail->link;
		list->tail->link = newnode;
		list->tail = newnode;
	}
}

void Del(List* list, int val) {
	if (list->tail == NULL) {
		printf("리스트가 없습니다.\n");
		return;
	}
	
	list->cur = list->tail->link;
	list->bef = list->tail;

	while (list->cur->data != val) {
		if (list->cur == list->tail) {
			printf("삭제할 값이 없습니다.\n");
			return;
		}

		list->bef = list->cur;
		list->cur = list->cur->link;
	}

	list->bef->link = list->cur->link;

	if (list->cur == list->tail) {
		list->tail = list->bef;
	}

	if (list->cur->link == list->cur) {
		list->tail = NULL;
	}

	free(list->cur);
}

void Display(List* list) {
	if (list->tail == NULL) {
		printf("리스트가 없습니다.\n");
		return;
	}

	list->cur = list->tail->link;

	while (list->cur != list->tail) {
		printf("%d -> ", list->cur->data);
		list->cur = list->cur->link;
	}
	printf("%d \n", list->cur->data);
}

int main() {
	List* list = malloc(sizeof(List));
	int select = 1, val;

	list->tail = NULL;
	list->cur = NULL;
	list->bef = NULL;

	while (select)
	{
		printf("1: 삽입 2: 삭제 3: 출력 0: 종료\n입력 : ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("값 입력:");
			scanf("%d", &val);
			Insert(list, val);
			break;
		case 2:
			printf("값 입력:");
			scanf("%d", &val);
			Del(list, val);
			break;
		case 3:
			Display(list);
			break;
		default:
			break;
		}
	}
} */

//양방향 연결리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* left;
	int data;
	struct Node* right;
}Node;

typedef struct list {
	Node* head;
	Node* cur;
}List;

void Insert(List* list, int val) {
	Node* newnode = malloc(sizeof(Node));
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;

	if (list->head == NULL)
	{
		list->head = newnode;
	}
	else
	{
		newnode->right = list->head;
		list->head->left = newnode;
		list->head = newnode;
	}
}

void Del(List* list, int val) {
	if (list->head == NULL) {
		printf("리스트가 없습니다.\n");
		return;
	}

	list->cur = list->head;

	while (list->cur->data != val)
	{
		if (list->cur->right == NULL) {
			printf("값이 없습니다.\n");
			return;
		}

		list->cur = list->cur->right;
	}

	//처음 노드일경우
	if (list->cur->left == NULL)
	{
		//노드가 하나만 남았을 경우
		if (list->cur->right == NULL)
		{
			list->head = NULL;
		}
		else
		{
			list->head = list->head->right;
			list->head->left = NULL;
		}
	}

	//마지막 노드일 경우
	else if (list->cur->right == NULL)
		list->cur->left->right = NULL;

	//중간 노드일경우
	else
	{
		list->cur->left->right = list->cur->right;
		list->cur->right->left = list->cur->left;
	}
	
	free(list->cur);
}

void Display(List* list) {
	if (list->head == NULL) {
		printf("리스트가 없습니다.\n");
		return;
	}

	list->cur = list->head;

	printf("오른쪽 : ");
	while (list->cur->right != NULL) {
		printf("%d -> ", list->cur->data);
		list->cur = list->cur->right;
	}
	printf("%d\n", list->cur->data);

	printf("왼쪽 : ");
	while (list->cur->left != NULL) {
		printf("%d -> ", list->cur->data);
		list->cur = list->cur->left;
	}
	printf("%d\n", list->cur->data);
}

int main() {
	List* list = malloc(sizeof(List));
	int select = 1, val;

	list->head = NULL;
	list->cur = NULL;

	while (select)
	{
		printf("1: 삽입 2: 삭제 3: 출력 0: 종료\n입력 : ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("값 입력:");
			scanf("%d", &val);
			Insert(list, val);
			break;
		case 2:
			printf("값 입력:");
			scanf("%d", &val);
			Del(list, val);
			break;
		case 3:
			Display(list);
			break;
		default:
			break;
		}
	}
}