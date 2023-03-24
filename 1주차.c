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
	printf("�й� : ");
	scanf("%d", &i_no);
	book[n].num = i_no;

	char i_name[20];
	printf("������ : ");
	scanf("%s", i_name);
	strcpy(book[n].name, i_name);

	int i_rent;
	printf("�뿩�� : ");
	scanf("%d", &i_rent);
	book[n].rent_day = i_rent;

	int i_return;
	printf("�ݳ��� : ");
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
	printf("%10s%10s%10s%10s\n", "�й�", "��������", "�뿩��", "�ݳ���");
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
		printf("1:�Է�\n2:�˻�\n3:���\n4:����\n");
		printf("----------------------\n");
		printf("���� : ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			n = Inser_book(book, n);
			break;
		case 2:
			printf("----------------------\n");
			printf("1:�й�\t2:�뿩��\t3:�ݳ���\n���� : ");
			scanf("%d", &select);
			printf("�� : ");
			scanf("%d", &value);
			Search(book, n, select, value);
			break;
		case 3:
			printf("-----------------------------------\n");
			printf("%10s%10s%10s%10s\n", "�й�", "��������", "�뿩��", "�ݳ���");
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