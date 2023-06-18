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




- 과제에 대한 고찰
키 값을 적절히 변형하여 직접적인 주소 값으로 매핑하는 해시 탐색 기법을 사용하는 과제를 수행하였다.
과제에 사용된 구조체 배열은 학생 정보의 리스트가 담겨있는 txt파일을 read하여 사용한다. 학생의 학번을
기준으로 테이블(Table)에 저장할 때 예를들어 학번이 20190896이라면 이것을 배열의 인덱스 값으로 저장할 경우 
배열의 크기가 매우 커질 것이며, 사용하지 않는 공간이 사용하는 공간보다 매우 많을 것이다. 따라서 이 배열 공간을
효율적으로 사용하기 위해 해시 함수의 접기 방법과 나눗셈 방법을 사용하여 해시테이블을 구성하였다. 이 과정에서 나눗셈
방법을 사용하였기에 충돌이 발생할 수 밖에 없다. 충돌을 해결하기 위해 충돌 발생시 고정 폭만큼 데이터가 비어있는 곳까지
주소를 이동시키는 선형 탐사법을 사용하여 최종적으로 구현하였다.
함수를 구현하는 과정에 막히는 부분이 조금 있었다. 접기 방법으로 각 자리를 아스키 코드값으로 변환하고 더하는 과정에
snprintf라는 함수를 사용하여 해결했고, 해시 테이블 구성하는 함수에서 char형의 값을 복사할 때 strcpy함수를 사용해서
해결했다. 
이렇게 구현된 코드의 수행시간은 충돌이 발생하지 않는다면 O(1)일 것이고, 충돌이 발생하여 선형 탐사법이 최악으로 작동
할 경우 수행시간은 O(Hash_Size)이다.

	
