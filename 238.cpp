#include<iostream>
#include<cstdlib>
#include<cstring>
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

	void insertToTail(Node *n)
	{
		this->tail->next = n;
		n->next = nullptr;
		this->tail = n;
	}

	void insertAfterHead(Node *n)
	{
		Node *p = this->head->next;
		n->next = p;
		head->next = n;
		if (head == tail)
			tail = n;
	}

	void insertAfterHead(int data)
	{
		Node *n = new Node(data);
		Node *p = this->head->next;
		n->next = p;
		head->next = n;
		if (head == tail)
			tail = n;
	}

	void mergeasc(LinkedList lb)
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

	void mergedesc(LinkedList lb)
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
		bool markdel = true;
		while (pa != nullptr)
		{
			while (pb2 != nullptr)
			{
				if (pa->data == pb2->data)
				{
					markdel = false;
					break;
				}
				pb2 = pb2->next;
			}
			pb2 = pb;
			if (markdel)
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
			markdel = true;
		}
		this->tail = pre;
	}

	void minus(LinkedList lb)
	{
		Node *pa = this->head->next, *pre = this->head;
		Node *pb = lb.head->next, *pb2 = pb;
		bool markdel = false;
		while (pa != nullptr)
		{
			while (pb2 != nullptr)
			{
				if (pa->data == pb2->data)
				{
					markdel = true;
					break;
				}
				pb2 = pb2->next;
			}
			pb2 = pb;
			if (markdel)
			{
				pre->next = pa->next;
				Node *p = pa;
				pa = pa->next;
				delete p;
				markdel = false;
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

	LinkedList* split()
	{//大于0的节点一个链表 小于0的节点一个链表
		LinkedList *l = new LinkedList[2];
		LinkedList *lb = new LinkedList(), *lc = new LinkedList();
		Node *p = this->head->next, *t;
		while (p != nullptr)
		{
			if (p->data < 0)
			{
				t = p->next;
				lb->insertToTail(p);
				p = t;
			}
			else if (0 < p->data)
			{
				t = p->next;
				lc->insertToTail(p);
				p = t;
			}
			else
				p = p->next;
		}
		l[0] = *lb; l[1] = *lc;
		return l;
	}

	int max()
	{
		int max = -2147483648;
		if (this->head->next == nullptr)
			return max;
		else
		{
			Node *p = this->head->next;
			while (p != nullptr)
			{
				if (p->data > max)
					max = p->data;
				p = p->next;
			}
			return max;
		}
	}

	void inverse()
	{
		Node *p = this->head->next, *q = p->next;
		this->tail = this->head;
		while (q != nullptr)
		{
			insertAfterHead(p);
			p = q;
			q = q->next;
		}
		insertAfterHead(p);
	}

	void rangedel(int min, int max)
	{
		Node *pre = this->head, *minp = this->head->next;
		while (minp != nullptr&&minp->data < min)
		{
			pre = minp;
			minp = minp->next;
		}
		if (minp == nullptr)  //最大的节点都小于min  没有要删除的
			return;
		if (min == max)  //只删除data=min=max的一个节点
		{
			if (minp->data == min)
			{
				pre->next = minp->next;
				if (this->tail == minp)
					this->tail = pre;
				delete minp;
			}
			return;
		}
		else
		{
			Node *maxp = minp->next;
			while (maxp != nullptr&&maxp->data <= max)
				maxp = maxp->next;
			if (maxp == nullptr)  //最大的节点≤max 说明要从minp删到结尾
			{
				this->tail = pre;
				while (minp != nullptr)
				{
					pre = minp;
					minp = minp->next;
					delete pre;
				}
				return;
			}
			else  //删除中间的一些节点
			{
				pre->next = maxp;
				while (minp != maxp)
				{
					pre = minp;
					minp = minp->next;
					delete pre;
				}
				return;
			}
		}
	}

	Node* NodeAt(int pos)
	{
		Node *n = this->head;
		while (n != nullptr&&pos--)
			n = n->next;
		return n;
	}

	void uniquify()
	{
		int saved[1000];
		memset(saved, 0, 1000 * sizeof(int));
		Node *p = this->head->next, *pre = this->head;
		while (p != nullptr)
		{
			if (saved[abs(p->data)])  //如果已经存在这个绝对值的节点 则把这个节点从链表中删除
			{
				pre->next = p->next;
				Node *q = p;
				p = p->next;
				delete q;
			}
			else
			{
				saved[abs(p->data)] = 1;
				pre = p;
				p = p->next;
			}
		}
		this->tail = pre;
	}

	void compare(LinkedList lb)
	{   //从头开始比对 找出最后一对匹配的字母
		Node *p = this->head, *q = lb.head;
		while (p->next != nullptr&&q->next != nullptr)
		{
			if (p->next->data == q->next->data)
			{
				p = p->next;
				q = q->next;
			}
			else
			{
				cout << static_cast<char>(p->data) << endl;
				return;
			}
		}
		cout << static_cast<char>(p->data) << endl;
	}

private:
	Node *tail;
};

int main()
{
	int lengthA,lengthB;
	char data;
	cin >> lengthA >> lengthB;
	while (lengthA != 0&&lengthB!=0)
	{
		LinkedList la,lb;
		while (lengthA--)
		{
			cin >> data;
			la.insertAfterHead(static_cast<int>(data));
		}
		while (lengthB--)
		{
			cin >> data;
			lb.insertAfterHead(static_cast<int>(data));
		}
		la.compare(lb);
		cin >> lengthA >> lengthB;
	}
	system("pause");
	return 0;
}