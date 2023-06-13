#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STD 20

typedef struct Student { //학생 정보
	int no; //학번
	char name[50]; //이름
	char tel[50]; //전화번호
}Std_Info;

int Hash_Function(int key, int Hash_Size); //해시 함수
void SInfo_Create(Std_Info* students, const char* file_name, int Hash_Size); //해시 테이블 구성
int Hash_Search(Std_Info* students, int key, int Hash_Size); //해시 탐색

int main() {
	Std_Info students[MAX_STD];
	const char* fName = "students_info.txt";

	for (int i = 0; i < MAX_STD; i++) { //students 해시 테이블 초기화
		students[i].no = -1;
		memset(students[i].name, 0, sizeof(students[i].name));
		memset(students[i].tel, 0, sizeof(students[i].tel));
	}
	SInfo_Create(students, fName, MAX_STD);
	printf("% d 위치는 해시 테이블 % d에 존재합니다.\n\n", 218, Hash_Search(students, 218, MAX_STD));
	printf("##해시 테이블##\n");
	for (int i = 0; i < MAX_STD; i++) //students 해시 테이블 출력
		printf("[% 2d]: % d % s % s\n", i, students[i].no, students[i].name, students[i].tel);

	return 0;
}

int Hash_Function(int key, int Hash_Size) { //해시 함수
	char buf[10];
	snprintf(buf, 10, "%d", key);

	int sum = 0;
	for (int i = 0; buf[i] != 0; i++) {
		int ascii = buf[i];
		sum += ascii;
	}

	int hash_addr = sum % Hash_Size;
	return hash_addr;
}
void SInfo_Create(Std_Info* students, const char* file_name, int Hash_Size) {//해시 테이블 구성
	FILE* file;
	fopen_s(&file, file_name, "r"); //read mode
	if (file == NULL) {
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return;
	}

	while (1) {
		int no;
		char name[50];
		char tel[50];
		int result = fscanf(file, "%d %s %s", &no, name, tel);
		if (result == EOF) break;
		int hash_addr = Hash_Function(no, Hash_Size);
		int index = hash_addr;
		while (students[index].no != -1) {
			if (students[index].no != -1) {
				if (students[index].no == no) {
					printf("error: duplicated key");
					return;
				}
				index = (index + 1) % Hash_Size;
				if (index == hash_addr) {
					printf("error: hash full");
					return;
				}
			}
		}
		students[index].no = no;
		strcpy(students[index].name, name);
		strcpy(students[index].tel, tel);
	}
	fclose(file);
}
int Hash_Search(Std_Info* students, int key, int Hash_Size) { //해시 탐색
	int hash_addr = Hash_Function(key, Hash_Size);
	int index = hash_addr;
	while (1) {
		if (students[index].no == key) return index;
		if (students[index].no == NULL) break;
		index = (index + 1) % Hash_Size;
		if (index == hash_addr) break;
	}
	return -1;
}
