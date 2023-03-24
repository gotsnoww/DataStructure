#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

typedef struct H {
	Node* head;
	Node* cur;
	Node* bef;
}H;

void insert(H* h, int val) {
	Node* newnode = malloc(sizeof(Node));

	newnode->data = val;
	newnode->link = NULL;

	if (h->head == NULL)
	{
		h->head = newnode;
		return;
	}
	else
	{
		//newnode �տ� �����ϴ� ���
		/*newnode->link = h->head;
		h->head = newnode;*/

		//newnode �ڿ� �����ϴ� ���
		h->cur = h->head;
		while (h->cur->link != NULL)
			h->cur = h->cur->link;

		h->cur->link = newnode;
	}
}

void Display(H* h) {
	if (h->head == NULL) {
		printf("���Ḯ��Ʈ�� �����ϴ�.\n\n");
		return;
	}
	
	h->cur = h->head;
	while (h->cur->link != NULL) {
		printf("%d -> ", h->cur->data);
		h->cur = h->cur->link;
	}
	printf("%d \n\n", h->cur->data);
}

void Delete(H* h, int val) {
	h->cur = h->head;

	while (h->cur != NULL) {
		if (h->cur->data == val) {
			if (h->cur == h->head) {
				h->head = h->head->link;
				free(h->cur);
			}
			else
			{
				h->bef->link = h->cur->link;
			}
			free(h->cur);
			return;
		}
		else {
			h->bef = h->cur;
			h->cur = h->cur->link;
		}
	}
}

int main() {
	H* h = malloc(sizeof(H));
	h->head = NULL;

	int select = 1, val;

	while (select)
	{
		printf("1: ���� 2: ���� 3: ��� 4: �˻� 0: ����\n �Է�: ");
		scanf("%d", &select);

		switch (select) {
		case 1:
			printf("�� �Է� : ");
			scanf("%d", &val);
			printf("\n");
			insert(h, val);
			break;
		case 2:
			printf("�� �Է� : ");
			scanf("%d", &val);
			Delete(h, val);
			break;
		case 3:
			Display(h);
		}
	}

	return 0;
}