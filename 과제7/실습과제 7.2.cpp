#include "MyMaxHeapTree.h"
#define MAX_HEAP_SIZE 20
int main()
{
	int maxHeap[MAX_HEAP_SIZE] = { 0, 35, 15, 30, 13, 9, 18, 10, 7, 4, 3, };
	int size = 10;
	TreePrinter(maxHeap, size); //기본 최대 힙 트리 출력
	Max_Heap_Insert(maxHeap, &size, 50); //키값 50 삽입
	TreePrinter(maxHeap, size); //삽입 결과 확인
	int tmp = Max_Heap_Remove(maxHeap, &size); //최대 힙 삭제 연산
	TreePrinter(maxHeap, size); //삭제 연산 결과 확인
	printf("Deleted Key: %d\n", tmp); //삭제된 결과 출력
	return 0;
}