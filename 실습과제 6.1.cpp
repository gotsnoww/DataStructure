#include <iostream>
#include "MyCircularQueue.hpp"
using namespace std;

int main(void) {
	CircularQueue<int> q;

	//������ ����
	q.Enqueue(5); q.Enqueue(33);
	q.Enqueue(25); q.Enqueue(17);

	//��ü ������ ����
	while (q.IsEmpty() == false) {
		printf("%d ", q.Dequeue());
	}

	return 0;
}
