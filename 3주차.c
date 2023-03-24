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
		//newnode 앞에 삽입하는 경우
		/*newnode->link = h->head;
		h->head = newnode;*/

		//newnode 뒤에 삽입하는 경우
		h->cur = h->head;
		while (h->cur->link != NULL)
			h->cur = h->cur->link;

		h->cur->link = newnode;
	}
}

void Display(H* h) {
	if (h->head == NULL) {
		printf("연결리스트가 없습니다.\n\n");
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
		printf("1: 삽입 2: 삭제 3: 출력 4: 검색 0: 종료\n 입력: ");
		scanf("%d", &select);

		switch (select) {
		case 1:
			printf("값 입력 : ");
			scanf("%d", &val);
			printf("\n");
			insert(h, val);
			break;
		case 2:
			printf("값 입력 : ");
			scanf("%d", &val);
			Delete(h, val);
			break;
		case 3:
			Display(h);
		}
	}

	return 0;
}