#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)

using namespace std;

#define ERROR -2147483647

struct Node
{
	int data;
	Node *next;

	Node()
	{
		data = 0;
		next = nullptr;
	}

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class Queue
{   //用带头结点的循环链表实现队列
public:
	Queue()
	{
		this->tail = new Node(ERROR);
	}

	bool isEmpty()
	{
		return tail->data == ERROR;
	}

	void enQueue(int data)
	{
		Node *p = new Node(data);
		if (isEmpty())
		{
			tail->next = p;
			p->next = tail;
			tail = p;
		}
		else
		{
			p->next = tail->next;
			tail->next = p;
			tail = p;
		}
	}

	int deQueue()
	{
		if (isEmpty())
			return ERROR;
		else
		{
			Node *firstElem = tail->next->next;
			Node *head = tail->next;
			int e = firstElem->data;
			head->next = firstElem->next;
			if (firstElem == tail)
				tail = head;
			return e;
		}
	}
private:
	Node *tail;
};

int main()
{
	int lengthIn, lengthOut,data;
	while (cin >> lengthIn >> lengthOut && lengthIn != 0 && lengthOut != 0)
	{
		Queue q;
		while (lengthIn--)
		{
			cin >> data;
			q.enQueue(data);
		}
		while (lengthOut--)
			cout << q.deQueue() << " ";
		cout << !q.isEmpty() << endl;
	}
	system("pause");
	return 0;
}