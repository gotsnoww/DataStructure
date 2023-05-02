#ifndef __MY_CIRCULAR_QUEUE_HPP__
#define __MY_CIRCULAR_QUEUE_HPP__
#define QUEUE_SIZE 100
template <typename T>
class CircularQueue {
private:
	int front; //������ ���� ��ġ(-1)
	int rear; //������ ������ ��ġ
	T* arr; //ť�� ������ ������ ���� ����
	int qSize; //ť�� ���̸� ����
public:
	CircularQueue() {
		front = -1;
		rear = -1;
		arr = new T[QUEUE_SIZE];
		qSize = QUEUE_SIZE;
	}
	CircularQueue(int size) {
		front = -1;
		rear = -1;
		arr = new T[size];
		qSize = size;
	}
	bool IsEmpty() {  //ť�� ��� �ִ��� Ȯ��
		if (front == rear)
			return true;
		else
			return false;
	}
	bool IsFull() {  //ť�� ���� �� �ִ��� Ȯ��
		if (front == ((rear + 1) % QUEUE_SIZE))
			return true;
		else
			return false;
	}
	bool Enqueue(T item) {  //ť�� �����͸� ����
		if(IsFull() == true)
			return false;
		rear = (rear + 1) % QUEUE_SIZE;
		arr[rear] = item;
	}
	T Dequeue() {  //ť���� �����͸� ����
		if (IsEmpty() == true)
			return -1;
		front = (front + 1) % QUEUE_SIZE;
		
		return arr[front];
	}
	T Peek() {  //�ֻ�� �����͸� Ȯ��
		return arr[front];
	}
	~CircularQueue() {
		delete[] arr;
	}
};
#endif
