#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

#define ERROR -2147483647
#define OK 0

class CrQueue
{
public:
	CrQueue()
	{
		base = new int[initSize];
		front = rear = 0;
	}

	int enQueue(int e)
	{
		if (rear == (front - 1 + initSize) % initSize)
			return ERROR;
		base[front] = e;
		front = (front - 1 + initSize) % initSize;
		return OK;
	}

	int deQueue()
	{
		if (front == rear)
			return ERROR;
		int e = base[rear];
		rear = (rear - 1 + initSize) % initSize;
		return e;
	}

private:
	int *base;
	int front;
	int rear;
	const static int initSize = 50;
};

int main()
{
	int length, data;
	while (cin >> length && length != 0)
	{
		CrQueue q;
		for (int i = 0; i < length; i++)
		{
			cin >> data;
			q.enQueue(data);
		}
		for (int j = 0; j < length - 1; j++)
			cout << q.deQueue() << " ";
		cout << q.deQueue() << endl;
	}
	system("pause");
	return 0;
}