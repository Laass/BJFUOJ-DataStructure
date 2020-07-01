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
		while (p->next != nullptr)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data << endl;
	}
private:
	Node *head;
};

int main()
{
	int length;
	while (cin >> length && length != 0)
	{
		LinkedList list = LinkedList(length);
		list.oddEvenSplit();
		list.traverse();
	}
	system("pause");
	return 0;
}