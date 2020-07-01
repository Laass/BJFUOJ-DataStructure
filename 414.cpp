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
		data = -1;
		next = nullptr;
	}
	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};
class LinkedList
{
public:
	LinkedList(int length)
	{
		head = new Node();
		Node *p = head;
		int data;
		while (length--)
		{
			cin >> data;
			p->next = new Node(data);
			p = p->next;
		}
	}
	void oddEvenSplit()
	{
		int pos = 1;
		Node *oddHead = head;
		Node *evenHead = new Node();
		Node *p = head,*q=evenHead;
		while (p ->next!= nullptr)
		{
			if (pos % 2 == 0)
			{
				q->next = p->next;
				p->next = p->next->next;
				q = q->next;
				q->next = nullptr;
			}
			else
				p = p->next;
			pos++;
		}
		p->next = evenHead->next;
		delete evenHead;
	}
	void traverse()
	{
		Node *p = head->next;
		if (p == nullptr)
		{
			cout << "The LinkList is Empty !" << endl;
			return;
		}
		while (p->next != nullptr)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data << endl;
	}
	int getLength()
	{
		int length = 0;
		Node *p = head->next;
		while (p != nullptr)
		{
			length++;
			p = p->next;
		}
		return length;
	}
	void delbackards(int pos)
	{
		Node *p = this->head;
		int length = getLength();
		int step = length - pos;
		while (step--)
			p = p->next;
		Node *q = p->next;
		p->next = p->next->next;
		delete q;
	}
private:
	Node *head;
};

int main()
{
	int length,pos;
	while (cin >> length && length != 0)
	{
		LinkedList list = LinkedList(length);
		cin >> pos;
		list.delbackards(pos);
		list.traverse();
	}
	system("pause");
	return 0;
}