#include<iostream>
#include<cstring>
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
		this->next = nullptr;
	}
};

class LinkedList
{
public:
	LinkedList()
	{
		head = new Node();
	}
	LinkedList(int length)
	{
		int data;
		head = new Node();
		Node *p = head;
		while (length--)
		{
			cin >> data;
			Node *n = new Node(data);
			p->next = n;
			p = n;
		}
	}
	Node *nodeAt(int pos)
	{
		Node *p = head;
		while (pos--&&p!=nullptr)
			p = p->next;
		return p;
	}
	int length()
	{
		int len = 0;
		Node *p = head->next;
		while (p!= nullptr)
		{
			len++;
			p = p->next;
		}
		return len;
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

void selectionSort(LinkedList &L)
{
	for (int i = 0; i < L.length() - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < L.length(); j++)
			if (L.nodeAt(k + 1)->data > L.nodeAt(j + 1)->data)
				k = j;
		if (k != i)
			swap(L.nodeAt(i + 1)->data, L.nodeAt(k + 1)->data);
	}
}

int main()
{
	int length;
	while (cin >> length && length != 0)
	{
		LinkedList L(length);
		selectionSort(L);
		L.traverse();
	}
	system("pause");
	return 0;
}