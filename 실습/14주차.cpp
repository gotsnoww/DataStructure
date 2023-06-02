#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void Display(int arr[]) {
	for (int i = 0; i < MAX; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n\n");
}

void Swap(int arr[], int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (arr[low] <= pivot && low <= high) {
			low++;
		}
		while (arr[high] >= pivot && high >= left + 1) {
			high--;
		}
		if (low <= high) {
			Swap(arr, low, high);
		}
	}
	Swap(arr, high, left); //high와 pivot값 교체
	printf("Pivot : %d\n", pivot);

	return high;
}

//삽입될 값 = temp 

void Quick_Sort(int arr[], int left, int right) {
	if (left < right)
	{
		int temp = Partition(arr, left, right);
		Display(arr);
		Quick_Sort(arr, left, temp - 1);
		Quick_Sort(arr, temp + 1, right);
	}
}

void Bubble(int B[]) {
	for (int i = MAX - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (B[j] > B[j + 1])
				Swap(B, j, j+1);
		}
		Display(B);
	}
}

void Insert(int I[]) {
	int temp, b_index;
	for (int i = 1; i < MAX; i++) {
		temp = I[i];
		for (b_index = i-1; b_index >= 0 && temp < I[b_index]; b_index--) {
			I[b_index + 1] = I[b_index];
		}
		I[b_index + 1] = temp;
		Display(I);
	}
}

void main() {
	srand(time(NULL));

	int B[MAX], I[MAX], Q[MAX];

	for (int i = 0; i < MAX; i++) {
		B[i] = rand() % 10 + 1;
		I[i] = B[i];
		Q[i] = B[i];
		for (int j = 0; j < i; j++) {
			if (B[i] == B[j]) {
				i--;
				break;
			}
		}
	}

	printf("---원본---\n");
	Display(B);

	printf("---퀵정렬---\n");
	Quick_Sort(Q, 0, MAX - 1);

	printf("---버블정렬---\n");
	Bubble(B);

	printf("---삽입정렬---\n");
	Insert(I);
}