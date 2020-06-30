#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

struct DCNode
{
	int data;
	DCNode *pre, *next;

	DCNode()
	{
		this->data = -2147483647;
		this->pre = this->next = nullptr;
	}

	DCNode(int data)
	{
		this->data = data;
		this->pre = this->next = nullptr;
	}
};

class DCList
{
public:
	DCNode *head;

	DCList()
	{
		this->head = new DCNode();
		this->head->next = this->head->pre = this->head;
	}

	void insertTotail(int data)
	{
		DCNode *n = new DCNode(data);
		if (this->head->next == this->head&&this->head->pre == this->head)
		{  //链表只有头结点
			this->head->next = n;
			n->pre = this->head;
			n->next = this->head;
			this->head->pre = n;
		}
		else 
		{
			DCNode *p = this->head;
			while (p->next != this->head)
				p = p->next;
			n->next = this->head; 
			n->pre = p;
			p->next = n;
			head->pre = n;
		}
	}

	void exchange(int pos)
	{  //交换第pos个节点和它前面节点的位置
		DCNode *n = this->head;
		while (pos--)
		{
			n = n->next;
			if (n == this->head) //位置错误 链表没有这么长
				return;
		}
		if (n->next == this->head && this->head->next == n)//如果只有头和一个节点 无需修改
			return;

		//至少有头和另外两个节点的情况
		DCNode *npre = n->pre, *epre = n->pre->pre, *enext = n->next;
		epre->next = n;
		n->pre = epre;
		n->next = npre;
		enext->pre = npre;
		npre->next = enext;
		npre->pre = n;
		return;
	}

	void traverse()
	{
		DCNode *p = this->head->next;
		while (p->next != this->head)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data << endl;
	}
};

int main()
{
	int length, data,pos;
	cin >> length;
	while (length != 0)
	{
		DCList l;
		while (length--)
		{
			cin >> data;
			l.insertTotail(data);
		}
		cin >> pos;
		l.exchange(pos);
		l.traverse();
		cin >> length;
	}
	system("pause");
	return 0;

}