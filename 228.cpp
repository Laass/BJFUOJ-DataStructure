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

	void insertAfterHead(Node *n)
	{
		Node *p = this->head->next;
		n->next = p;
		head->next = n;
		if (head == tail)
			tail = n;
	}

	void mergeAsc(LinkedList lb)
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

	void mergeDesc(LinkedList lb)
	{
		Node *pa = this->head->next, *pb = lb.head->next;
		Node *p = nullptr;
		this->tail = this->head;
		this->head->next = nullptr;
		while (pa != nullptr&&pb != nullptr)
		{
			if (pa->data < pb->data)
			{
				p = pa;
				pa = pa->next;
				p->next = nullptr;
				insertAfterHead(p);
			}
			else if (pb->data < pa->data)
			{
				p = pb;
				pb = pb->next;
				p->next = nullptr;
				insertAfterHead(p);
			}
			else
			{
				p = pa;
				pa = pa->next;
				p->next = nullptr;
				insertAfterHead(p);

				p = pb;
				pb = pb->next;
				p->next = nullptr;
				insertAfterHead(p);
			}
		}
		while (pa != nullptr)
		{
			p = pa;
			pa = pa->next;
			p->next = nullptr;
			insertAfterHead(p);
		}
		while (pb != nullptr)
		{
			p = pb;
			pb = pb->next;
			p->next = nullptr;
			insertAfterHead(p);
		}
	}

	void intersect(LinkedList lb)
	{
		Node *pa = this->head->next, *pre = this->head;
		Node *pb = lb.head->next, *pb2 = pb;
		bool markDel = true;
		while (pa != nullptr)
		{
			while (pb2 != nullptr)
			{
				if (pa->data == pb2->data)
				{
					markDel = false;
					break;
				}
				pb2 = pb2->next;
			}
			pb2 = pb;
			if (markDel)
			{
				pre->next = pa->next;
				Node *p = pa;
				pa = pa->next;
				delete p;
			}
			else
			{
				pre = pa;
				pa = pa->next;
			}
			markDel = true;
		}
		this->tail = pre;
	}

	void minus(LinkedList lb)
	{// 也可以利用两个链表递增的特点 la的节点与lb中小于等于它的节点比 下个la的节点从上次停止的节点（lb中的）后一个开始比对
		Node *pa = this->head->next, *pre = this->head;
		Node *pb = lb.head->next, *pb2 = pb;
		bool markDel = false;
		while (pa != nullptr)
		{
			while (pb2 != nullptr)
			{
				if (pa->data == pb2->data)
				{
					markDel = true;
					break;
				}
				pb2 = pb2->next;
			}
			pb2 = pb;
			if (markDel)
			{
				pre->next = pa->next;
				Node *p = pa;
				pa = pa->next;
				delete p;
				markDel = false;
			}
			else
			{
				pre = pa;
				pa = pa->next;
			}
		}
		this->tail = pre;

	}

	int length()
	{
		if (this->head->next == nullptr)
			return 0;
		else
		{
			Node *p = this->head->next;
			int count = 0;
			while (p != nullptr)
			{
				count++;
				p = p->next;
			}
			return count;
		}
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
		la.minus(lb);
		la.traverse();
		cout << la.length() << endl;
		cin >> aLength >> bLength;
	}
	return 0;
}