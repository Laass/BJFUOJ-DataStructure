#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

struct Node
{
	int data;
	Node *next;

	Node()
	{
		this->data = -1;
		this->next = nullptr;
	}

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList
{
public:
	Node *head;

	LinkedList()
	{
		this->head = new Node();
		this->tail = head;
	}

	void insertToTail(int data)
	{
		Node *n = new Node(data);
		tail->next = n;
		tail = n;
	}

	void merge(LinkedList lb)
	{
		Node *pa = this->head->next, *pb = lb.head->next;
		this->tail = this->head;
		while (pa != nullptr&&pb != nullptr)
		{
			if (pa->data < pb->data)
			{
				tail->next = pa;
				tail = pa;
				pa = pa->next;

			}
			else if (pb->data < pa->data)
			{
				tail->next = pb;
				tail = pb;
				pb = pb->next;
			}
			else
			{
				tail->next = pa;
				tail = pa;
				pa = pa->next;
				pb = pb->next;
			}
		}
		if (pa != nullptr)
			tail->next = pa;
		if (pb != nullptr)
			tail->next = pb;
		while (tail->next != nullptr)
			tail = tail->next;
	}

	void traverse()
	{
		Node *p = this->head;
		while (p->next != nullptr&&p->next != this->tail)
		{
			p = p->next;
			cout << p->data << " ";
		}
		cout << tail->data << endl;
	}

private:
	Node *tail;
};

int main()
{
	int aLength, bLength, data;
	cin >> aLength >> bLength;
	while (aLength != 0 && bLength != 0)
	{
		LinkedList la, lb;
		for (int i = 0; i < aLength; i++)
		{
			cin >> data;
			la.insertToTail(data);
		}
		for (int j = 0; j < bLength; j++)
		{
			cin >> data;
			lb.insertToTail(data);
		}
		la.merge(lb);
		la.traverse();
		cin >> aLength >> bLength;
	}
	return 0;
}