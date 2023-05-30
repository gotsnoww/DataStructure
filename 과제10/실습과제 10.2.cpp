#include "MyGraphSP.h"
#include <limits.h>
int main() {
	const char* file = "g_file4.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	int* path = new int[num_of_ver];

	for (int i = 0; i < num_of_ver; i++) { //그래프 초기화
		path[i] = 0;
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) weight_mat[i][j] = INT_MAX;
		}
	}

	ADJ_Create(file, weight_mat); //가중치 그래프를 인접 행렬로 생성
	printf("##가중치 그래프##\n");
	ADJ_Print_Array(weight_mat, num_of_ver); //인접 행렬 출력
	printf("##최단 거리##\n");
	Shortest_Path(weight_mat, num_of_ver, 0, path); //최단거리 계산
	printf("\n##최단 거리 경로##\n");

	for (int i = 0; i < num_of_ver; i++) {
		PrintPath(path, 0, i); //시작 정점0부터 모든 정점 사이의 최단거리 경로
		printf("\n");
	}

	return 0;
}