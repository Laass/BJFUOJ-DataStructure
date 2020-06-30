#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)

using namespace std;

#define ERROR -2147483647

class CrQueue
{
public:
	CrQueue()
	{
		base = new int[initSize];
		front = rear = 0;
		emptyTag = true;
	}

	int enQueue(int e)
	{
		if (rear == front && !emptyTag)
			return ERROR;
		base[rear] = e;
		rear = (rear + 1) % initSize;
		emptyTag = false;
	}

	int deQueue()
	{
		if (isEmpty())
			return ERROR;
		int e = base[front];
		front = (front + 1) % initSize;
		if (front == rear)
			emptyTag = true;
		return e;
	}

	bool isEmpty()
	{
		return rear == front && emptyTag;
	}
private:
	int *base;
	int front;
	int rear;
	bool emptyTag;
	const static int initSize = 20;
};

int main()
{
	int length, data, len;
	while (cin >> length && length != 0)
	{
		len = length;
		CrQueue q;
		while (len--)
		{
			cin >> data;
			q.enQueue(data);
		}
		len = length - 1;
		while (len--)
			cout << q.deQueue() << " ";
		cout << q.deQueue() << endl;
	}
	return 0;
}