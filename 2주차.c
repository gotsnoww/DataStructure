#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	int no;
	char name[20];
	int mid;
	int fi;
} Student;

void Insert(Student* stu, int i)
{
	printf("�й� : ");
	scanf("%d", &stu[i].no); //&(stu+i)->no
	printf("�̸� : ");
	scanf("%s", stu[i].name);
	printf("�߰� : ");
	scanf("%d", &stu[i].mid);
	printf("�⸻ : ");
	scanf("%d", &stu[i].fi);
}

void Display(Student* stu, int n) {
	printf("%10s%10s%10s%10s\n", "�й�", "�̸�", "�߰�", "�⸻");

	for (int i = 0; i < n; i++)
	{
		printf("%10d", (stu + i)->no);
		printf("%10s", stu[i].name);
		printf("%10d", (stu + i)->mid);
		printf("%10d", (stu + i)->fi);
		printf("\n");
	}
}

void Sort(Student* stu, int n) {
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if ((stu[j].mid + stu[j].fi) < (stu[j + 1].mid + stu[j + 1].fi))
			{
				Student temp;  //swap
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
		}
	}
}

int main() {
	int n;
	Student* stu = NULL;

	printf("�л� �� �Է� : ");
	scanf("%d", &n);
	int count = n;

	stu = malloc(sizeof(Student) * n);

	for (int i = 0; i < n; i++) {
		Insert(stu, i);
	}

	printf("------------------����-----------------\n");
	Display(stu, n);
	printf("------------------����-----------------\n");
	
	Sort(stu, n);

	printf("------------------����-----------------\n");
	Display(stu, n);
	printf("------------------����-----------------\n");
	printf("\n");

	
	printf("�߰� �л� : "); //�߰� �л� �Է�
	scanf("%d", &n);

	int std_num = count + n;
	realloc(stu, sizeof(Student) * std_num);

	for (int i = 0; i < n; i++) {
		Insert(stu, (i+count));
	}

	Sort(stu, std_num);

	printf("------------------����-----------------\n");
	Display(stu, std_num);
	printf("------------------����-----------------\n");

	return 0;
}