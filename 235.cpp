#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

struct node
{
	int data;
	node *next;

	node()
	{
		this->data = -1;
		this->next = nullptr;
	}

	node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class linkedlist
{
public:
	node *head;

	linkedlist()
	{
		this->head = new node();
		this->tail = head;
	}

	void inserttotail(int data)
	{
		node *n = new node(data);
		tail->next = n;
		tail = n;
	}

	void inserttotail(node *n)
	{
		this->tail->next = n;
		n->next = nullptr;
		this->tail = n;
	}

	void insertafterhead(node *n)
	{
		node *p = this->head->next;
		n->next = p;
		head->next = n;
		if (head == tail)
			tail = n;
	}

	void mergeasc(linkedlist lb)
	{
		node *pa = this->head->next, *pb = lb.head->next;
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
		node *p = this->head;
		while (p->next != nullptr&&p->next != this->tail)
		{
			p = p->next;
			cout << p->data << " ";
		}
		cout << tail->data << endl;
	}

	void mergedesc(linkedlist lb)
	{
		node *pa = this->head->next, *pb = lb.head->next;
		node *p = nullptr;
		this->tail = this->head;
		this->head->next = nullptr;
		while (pa != nullptr&&pb != nullptr)
		{
			if (pa->data < pb->data)
			{
				p = pa;
				pa = pa->next;
				p->next = nullptr;
				insertafterhead(p);
			}
			else if (pb->data < pa->data)
			{
				p = pb;
				pb = pb->next;
				p->next = nullptr;
				insertafterhead(p);
			}
			else
			{
				p = pa;
				pa = pa->next;
				p->next = nullptr;
				insertafterhead(p);

				p = pb;
				pb = pb->next;
				p->next = nullptr;
				insertafterhead(p);
			}
		}
		while (pa != nullptr)
		{
			p = pa;
			pa = pa->next;
			p->next = nullptr;
			insertafterhead(p);
		}
		while (pb != nullptr)
		{
			p = pb;
			pb = pb->next;
			p->next = nullptr;
			insertafterhead(p);
		}
	}

	void intersect(linkedlist lb)
	{
		node *pa = this->head->next, *pre = this->head;
		node *pb = lb.head->next, *pb2 = pb;
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
				node *p = pa;
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

	void minus(linkedlist lb)
	{
		node *pa = this->head->next, *pre = this->head;
		node *pb = lb.head->next, *pb2 = pb;
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
				node *p = pa;
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
			node *p = this->head->next;
			int count = 0;
			while (p != nullptr)
			{
				count++;
				p = p->next;
			}
			return count;
		}
	}

	linkedlist* split()
	{//大于0的节点一个链表 小于0的节点一个链表
		linkedlist *l = new linkedlist[2];
		linkedlist *lb = new linkedlist(), *lc = new linkedlist();
		node *p = this->head->next, *t;
		while (p != nullptr)
		{
			if (p->data < 0)
			{
				t = p->next;
				lb->inserttotail(p);
				p = t;
			}
			else if (0 < p->data)
			{
				t = p->next;
				lc->inserttotail(p);
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
			node *p = this->head->next;
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
		node *p = this->head->next, *q = p->next;
		this->tail = this->head;
		while (q != nullptr)
		{
			insertafterhead(p);
			p = q;
			q = q->next;
		}
		insertafterhead(p);
	}

	void rangedel(int min, int max)
	{
		node *pre = this->head, *minp = this->head->next;
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
			node *maxp = minp->next;
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

	node* nodeAt(int pos)
	{
		node *n = this->head;
		while (n != nullptr&&pos--)
			n = n->next;
		return n;
	}



private:
	node *tail;
};

int main()
{
	int length, data, pos;
	cin >> length;
	while (length != 0)
	{
		int i = length;
		linkedlist la;
		while (i--)
		{
			cin >> data;
			la.inserttotail(data);
		}
		cin >> pos;
		cout << la.nodeAt(length - pos + 1)->data << endl;
		cin >> length;
	}
	return 0;
}#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

struct node
{
	int data;
	node *next;

	node()
	{
		this->data = -1;
		this->next = nullptr;
	}

	node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class linkedlist
{
public:
	node *head;

	linkedlist()
	{
		this->head = new node();
		this->tail = head;
	}

	void inserttotail(int data)
	{
		node *n = new node(data);
		tail->next = n;
		tail = n;
	}

	void inserttotail(node *n)
	{
		this->tail->next = n;
		n->next = nullptr;
		this->tail = n;
	}

	void insertafterhead(node *n)
	{
		node *p = this->head->next;
		n->next = p;
		head->next = n;
		if (head == tail)
			tail = n;
	}

	void mergeasc(linkedlist lb)
	{
		node *pa = this->head->next, *pb = lb.head->next;
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
		node *p = this->head;
		while (p->next != nullptr&&p->next != this->tail)
		{
			p = p->next;
			cout << p->data << " ";
		}
		cout << tail->data << endl;
	}

	void mergedesc(linkedlist lb)
	{
		node *pa = this->head->next, *pb = lb.head->next;
		node *p = nullptr;
		this->tail = this->head;
		this->head->next = nullptr;
		while (pa != nullptr&&pb != nullptr)
		{
			if (pa->data < pb->data)
			{
				p = pa;
				pa = pa->next;
				p->next = nullptr;
				insertafterhead(p);
			}
			else if (pb->data < pa->data)
			{
				p = pb;
				pb = pb->next;
				p->next = nullptr;
				insertafterhead(p);
			}
			else
			{
				p = pa;
				pa = pa->next;
				p->next = nullptr;
				insertafterhead(p);

				p = pb;
				pb = pb->next;
				p->next = nullptr;
				insertafterhead(p);
			}
		}
		while (pa != nullptr)
		{
			p = pa;
			pa = pa->next;
			p->next = nullptr;
			insertafterhead(p);
		}
		while (pb != nullptr)
		{
			p = pb;
			pb = pb->next;
			p->next = nullptr;
			insertafterhead(p);
		}
	}

	void intersect(linkedlist lb)
	{
		node *pa = this->head->next, *pre = this->head;
		node *pb = lb.head->next, *pb2 = pb;
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
				node *p = pa;
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

	void minus(linkedlist lb)
	{
		node *pa = this->head->next, *pre = this->head;
		node *pb = lb.head->next, *pb2 = pb;
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
				node *p = pa;
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
			node *p = this->head->next;
			int count = 0;
			while (p != nullptr)
			{
				count++;
				p = p->next;
			}
			return count;
		}
	}

	linkedlist* split()
	{//大于0的节点一个链表 小于0的节点一个链表
		linkedlist *l = new linkedlist[2];
		linkedlist *lb = new linkedlist(), *lc = new linkedlist();
		node *p = this->head->next, *t;
		while (p != nullptr)
		{
			if (p->data < 0)
			{
				t = p->next;
				lb->inserttotail(p);
				p = t;
			}
			else if (0 < p->data)
			{
				t = p->next;
				lc->inserttotail(p);
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
			node *p = this->head->next;
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
		node *p = this->head->next, *q = p->next;
		this->tail = this->head;
		while (q != nullptr)
		{
			insertafterhead(p);
			p = q;
			q = q->next;
		}
		insertafterhead(p);
	}

	void rangedel(int min, int max)
	{
		node *pre = this->head, *minp = this->head->next;
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
			node *maxp = minp->next;
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

	node* nodeAt(int pos)
	{
		node *n = this->head;
		while (n != nullptr&&pos--)
			n = n->next;
		return n;
	}



private:
	node *tail;
};

int main()
{
	int length, data, pos;
	cin >> length;
	while (length != 0)
	{
		int i = length;
		linkedlist la;
		while (i--)
		{
			cin >> data;
			la.inserttotail(data);
		}
		cin >> pos;
		cout << la.nodeAt(length - pos + 1)->data << endl;
		cin >> length;
	}
	return 0;
}