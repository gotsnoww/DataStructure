#include "MyGraphMST.h"
#include <limits.h>

int main()
{
	const char* file = "g_file3.txt";
	int weight_mat[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int MST[MAX_VERTICES][MAX_VERTICES] = { 0 };
	int num_of_ver = 7;
	for (int i = 0; i < num_of_ver; i++) { //그래프 초기화
		for (int j = 0; j < num_of_ver; j++) {
			if (i != j) {
				weight_mat[i][j] = INT_MAX;
				MST[i][j] = INT_MAX;
			}
		}
	}

	ADJ_Create(file, weight_mat); //가중치 그래프를 인접 행렬로 생성
	printf("가중치 그래프: \n");
	ADJ_Print_Array(weight_mat, num_of_ver); //인접 행렬 출력
	MST_Prim(weight_mat, MST, num_of_ver); //프림 알고리즘을 활용한 MST 구성
	printf("MST: \n");
	ADJ_Print_Array(MST, num_of_ver); //MST 행렬 출력

	return 0;
}
