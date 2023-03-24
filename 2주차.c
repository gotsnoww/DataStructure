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
	printf("학번 : ");
	scanf("%d", &stu[i].no); //&(stu+i)->no
	printf("이름 : ");
	scanf("%s", stu[i].name);
	printf("중간 : ");
	scanf("%d", &stu[i].mid);
	printf("기말 : ");
	scanf("%d", &stu[i].fi);
}

void Display(Student* stu, int n) {
	printf("%10s%10s%10s%10s\n", "학번", "이름", "중간", "기말");

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

	printf("학생 수 입력 : ");
	scanf("%d", &n);
	int count = n;

	stu = malloc(sizeof(Student) * n);

	for (int i = 0; i < n; i++) {
		Insert(stu, i);
	}

	printf("------------------원본-----------------\n");
	Display(stu, n);
	printf("------------------원본-----------------\n");
	
	Sort(stu, n);

	printf("------------------원본-----------------\n");
	Display(stu, n);
	printf("------------------원본-----------------\n");
	printf("\n");

	
	printf("추가 학생 : "); //추가 학생 입력
	scanf("%d", &n);

	int std_num = count + n;
	realloc(stu, sizeof(Student) * std_num);

	for (int i = 0; i < n; i++) {
		Insert(stu, (i+count));
	}

	Sort(stu, std_num);

	printf("------------------원본-----------------\n");
	Display(stu, std_num);
	printf("------------------원본-----------------\n");

	return 0;
}