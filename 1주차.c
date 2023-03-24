#include <stdio.h>
#include <string.h>

typedef struct info_book
{
	int num;
	char name[20];
	int rent_day;
	int return_day;
}ib;

int Inser_book(ib book[100], int n)
{
	int i_no;
	printf("학번 : ");
	scanf("%d", &i_no);
	book[n].num = i_no;

	char i_name[20];
	printf("도서명 : ");
	scanf("%s", i_name);
	strcpy(book[n].name, i_name);

	int i_rent;
	printf("대여일 : ");
	scanf("%d", &i_rent);
	book[n].rent_day = i_rent;

	int i_return;
	printf("반납일 : ");
	scanf("%d", &i_return);
	book[n].return_day = i_return;

	return ++n;
}
void Display(ib b1)
{
	printf("%10d%10s%10d%10d\n", b1.num, b1.name, b1.rent_day, b1.return_day);
}
void Search(ib* book, int n, int select, int value)
{
	printf("-----------------------------------\n");
	printf("%10s%10s%10s%10s\n", "학번", "도서정보", "대여일", "반납일");
	printf("-----------------------------------\n");
	switch (select)
	{
	case 1:
		for (int i = 0; i < n; i++)
		{
			if (book[i].num == value)
			{
				Display(book[i]);
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; i++)
		{
			if (book[i].rent_day == value)
			{
				Display(book[i]);
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; i++)
		{
			if (book[i].return_day == value)
			{
				Display(book[i]);
			}
		}
		break;
	default:
		break;
	}
	printf("-----------------------------------\n");
}
void main()
{
	ib book[100];
	int menu = 1, n = 0, select, value;
	while (menu)
	{
		printf("1:입력\n2:검색\n3:출력\n4:종료\n");
		printf("----------------------\n");
		printf("선택 : ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			n = Inser_book(book, n);
			break;
		case 2:
			printf("----------------------\n");
			printf("1:학번\t2:대여일\t3:반납일\n선택 : ");
			scanf("%d", &select);
			printf("값 : ");
			scanf("%d", &value);
			Search(book, n, select, value);
			break;
		case 3:
			printf("-----------------------------------\n");
			printf("%10s%10s%10s%10s\n", "학번", "도서정보", "대여일", "반납일");
			printf("-----------------------------------\n");
			for (int i = 0; i < n; i++)
			{
				Display(book[i]);
			}
			printf("-----------------------------------\n");
			break;
		case 4:
			menu = 0;
		default:
			break;
		}
	}

}