#include<iostream>
#include<cstdlib>
using namespace std;
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

class LinkedList
{
public:
	LinkedList(int num)
	{
		head = new Node();
		Node *p;
		int data;
		while (num--)
		{
			cin >> data;
			p = new Node(data);
			p->next = this->head->next;
			this->head->next = p;
		}
		this->maxVal = 0;
	}

	int max()
	{
		getMax(head->next);
		return this->maxVal;
	}

	int length()
	{
		if (head->next == nullptr)
			return 0;
		else
			return getLength(head->next);
	}
private:
	Node *head;
	int maxVal;
	void getMax(Node *p)
	{
		if (this->maxVal < p->data)
			this->maxVal = p->data;
		if (p->next != nullptr)
			getMax(p->next);
	}
	int getLength(Node *p)
	{
		if (p == nullptr)
			return 0;
		else
			return getLength(p->next) + 1;
	}
};

int main()
{
	int length;
	while (cin >> length && length != 0)
	{
		LinkedList l(length);
		cout << l.length() << endl;
	}
	system("pause");
	return 0;
}