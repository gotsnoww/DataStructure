#include <iostream>
#include <cmath>
using namespace std;

//tree 출력 함수
void PrintTree2Matrix(int** M, int* bTree, int size, int idx, int col, int row, int height) {
	if (idx > size) return;
	M[row][col] = bTree[idx];
	PrintTree2Matrix(M, bTree, size, idx * 2, col - pow(2, height - 2), row + 1, height - 1);
	PrintTree2Matrix(M, bTree, size, idx * 2 + 1, col + pow(2, height - 2), row + 1, height - 1);
}
void TreePrinter(int* bTree, int size) {
	int h = (int)ceil(log2(size + 1));
	int col = (1 << h) - 1;
	int** M = new int* [h];
	for (int i = 0; i < h; i++) {
		M[i] = new int[col];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
	PrintTree2Matrix(M, bTree, size, 1, col / 2, 0, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j] == 0)
				printf(" ");
			else
				printf("%2d", M[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
}

//tree Node 출력 함수
void PrintAncestor(int* bTree, int size, int idx) {
	printf("%d의 모든 조상 노드: ", bTree[idx]);

	int p = idx;
	while (p > 1) {
		p /= 2;
		printf("%d ", bTree[p]);
	}
	printf("\n");
} //왼쪽 후손 노드 출력 함수
void PrintLeftDescendant(int* bTree, int size, int idx) {
	printf("%d의 모든 왼쪽 후손 노드: ", bTree[idx]);

	int height = log2(size+1);
	int ls = idx;

	for (int i = 1; i < height; i++) {
		ls = 2 * ls;
		printf("%d ", bTree[ls]);
	}
	printf("\n");
} //오른쪽 후손 노드 출력 함수
void PrintRightDescendant(int* bTree, int size, int idx) {
	printf("%d의 모든 오른쪽 후손 노드: ", bTree[idx]);
	int height = log2(size + 1);
	int rs = idx;

	for (int i = 1; i < height; i++) {
		rs = 2 * rs + 1;
		printf("%d ", bTree[rs]);
	}
	printf("\n");
} //노드의 index를 탐색하는 함수
int FindNode(int* bTree, int size, int data) {
	int temp = 0;
	for (int i = 1; i <= size; i++) {
		if (bTree[i] == data)
			temp = i;
	}
	
	return temp;
}

int main() {
	int full_bTree[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 55, 35, 65,75,25,91 };
	int size = sizeof(full_bTree) / sizeof(full_bTree[0]) - 1;

	TreePrinter(full_bTree, size);
	PrintAncestor(full_bTree, size, 14);
	PrintLeftDescendant(full_bTree, size, 1);
	PrintRightDescendant(full_bTree, size, 1);

	printf("%d 노드의 인덱스는 %d 입니다. \n", 30, FindNode(full_bTree, size, 30));

	return 0;
}


- 과제에 대한 고찰
트리라는 자료구조에 대하여 배워보았다. 기존에 트리라는 자료구조에 대해서는 어느정도 알고 있었지만,
이렇게 자세히 배운 것은 처음이었다. 트리의 노드별 관계와 용어, 서브트리, 이진트리 등 이러한 것들을
배우고 이를 과제와 접목시켜 수행하였다.
과제로 진행한 트리는 완전 이진 트리이다. 이 트리의 조상, 후손 노드를 구하는 함수들을 구현하고
특정 노드의 인덱스를 찾는 함수를 구현하였다. 이렇게 구현된 코드의 수행시간은 트리의 높이에 따라 결정된다.
따라서 수행시간은 O(logn)이 되겠다. 수행공간은 트리의 크기에 비례할 것이다.
각 함수를 살펴보면 트리의 높이를 구하고 높이만큼 반복문을 수행하여 노드를 찾아낸다.
