#include<iostream>
#include<cstdlib>
#include<iomanip>
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
		this->sum = 0;
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

	float avg()
	{
		if (head->next == nullptr)
			return ERROR;
		return (float)getSum(head->next) / length();
	}
private:
	Node *head;
	int maxVal;
	int sum;
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
	int getSum(Node *p)
	{
		if (p == nullptr)
			return sum;
		else
		{
			sum += p->data;
			return getSum(p->next);
		}
	}
};

int main()
{
	int length;
	while (cin >> length && length != 0)
	{
		LinkedList l(length);
		cout << setiosflags(ios::fixed) << setprecision(2) << l.avg() << endl;
	}
	system("pause");
	return 0;
}  