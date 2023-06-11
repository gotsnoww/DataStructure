#include <cstdio>

void swap(int* n1, int* n2);
void Quick_Sort(int* random_data, int left, int right);
int Partition(int* random_data, int left, int right);
int Seq_Search(int* random_data, int key, int n);
int Bin_Search(int* random_data, int key, int n);

int main()
{
	int random_data[] = { 27, 4, 37, 2, 62, 12, 59, 16, 49, 18 };
	int size = sizeof(random_data) / sizeof(int);
	printf("정렬 전 데이터: ");

	for (int i = 0; i < size; i++) { printf("%d ", random_data[i]); }
	int result = Seq_Search(random_data, 49, size);
	printf("\n\n##순차 탐색##\n");

	if (result != -1) printf("값 %d는 %d 번째에 존재합니다.\n\n", random_data[result], result);
	Quick_Sort(random_data, 0, size - 1);
	printf("정렬 후 데이터: ");
	for (int i = 0; i < size; i++) { printf("%d ", random_data[i]); }
	printf("\n\n##이진 탐색##\n");

	int key = 52;
	result = Bin_Search(random_data, key, size);
	if (result == -1) printf("%d 값은 존재하지 않습니다.\n", key);
	key = 37;
	result = Bin_Search(random_data, key, size);
	if (result != -1) printf("값 %d는 %d 번째에 존재합니다.\n", key, result);

	return 0;
}

void swap(int* n1, int* n2) { //스왑 함수
	int temp = 0;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void Quick_Sort(int* random_data, int left, int right) { //퀵 정렬 함수
	if (left < right) {
		int q = Partition(random_data, left, right);
		Quick_Sort(random_data, left, q - 1);
		Quick_Sort(random_data, q + 1, right);
	}
}
int Partition(int* random_data, int left, int right) { //분할 함수
	int low = left + 1; //제일 왼쪽 데이터는 pivot으로 활용
	int high = right;
	int pivot = random_data[left]; 
	while (low <= high) {
		while (random_data[high] > pivot) //pivot보다 작은 값 탐색
			high -= 1;
		while ((low <= high) && (random_data[low] <= pivot)) //pivot보다 큰 값 탐색
			low += 1;
		if (low <= high) {
			swap(&random_data[low], &random_data[high]);
			low += 1;
			high -= 1;
		}
	}
	//pivot 값과 high 값 교환
	swap(&random_data[left], &random_data[high]);
	return high;
}
int Seq_Search(int* random_data, int key, int n) { //순차 탐색 함수
	for (int i = 0; i < n; i++) {
		if (key == random_data[i])
			return i; //찾고자하는 데이터의 위치 반환
	}
	return NULL;
}
int Bin_Search(int* random_data, int key, int n) { //이진 탐색 함수
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (key == random_data[mid]) return mid; //찾고자하는 데이터의 위치 반환
		if (key > random_data[mid]) left = mid + 1; //오른쪽 영역으로 한정
		else right = mid - 1; //왼쪽 영역으로 한정
	}
	return -1;
}


- 과제에 대한 고찰
배열의 값을 탐색하는 방법 두 가지인 순차 탐색과 이진 탐색 방법을 사용하여 특정 키 값을 탐색한다.
과제에서는 랜덤 데이터 배열을 메인함수에서 첫 부분에 생성하고, 이를 사용하여 탐색하는 방식이다.
우선 순차 탐색은 배열의 처음부터 끝까지 차례대로 모든 요소를 비교하며 탐색하는 알고리즘으로, 정렬되지
않은 데이터를 탐색할 때 사용되며 구현이 매우 간단하다. 이진 탐색은 정렬된 데이터를 탐색하기에 적합하기
때문에, 11.2에서 구현한 퀵 정렬을 사용하여 배열을 정렬해준 후 이진 탐색을 수행한다. 퀵 정렬은 분할 정복
방법을 사용하며, 평균적으로 가장 빠른 정렬 방법이다. pivot을 선정하며 pivot을 기준으로 작은 값은 왼쪽에, 
큰 값은 우측에 정렬한다. low와 high가 교차되면 high와 pivot을 교환하는 방식을 배열이 정렬될 때까지 반복한다.
이렇게 정렬된 배열을 사용하여 이진 탐색을 진행한다. 이진 탐색은 순차 탐색에 비해 구현이 좀 더 어렵지만 빠른
속도로 탐색이 가능하기 때문에 수행시간에 있어서 효율적인 탐색 방법이라 할 수 있다.
순차탐색의 경우 배열의 index 개수에 따라 수행시간이 정해지므로 시간복잡도는 O(n)이고, 이진탐색은 운이 좋으면
찾고자 하는 값이 중간값과 동일해서 탐색이 끝나지만, 최악의 경우 남은 데이터가 하나가 될 때까지 탐색을 반복하므로
이진탐색의 시간복잡도는 O(logn)이다.

