#include<iostream>
#include<cstring>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

struct DualNode
{
	int data;
	DualNode *pre, *next;
	DualNode()
	{
		data = -1;
		pre = next = nullptr;
	}
	DualNode(int data)
	{
		this->data = data;
		pre = next = nullptr;
	}
};

class DualList
{
public:
	DualList()
	{
		head = new DualNode();
	}
	DualList(int length)
	{
		head = new DualNode();
		int data;
		DualNode *p = head;
		while (length--)
		{
			cin >> data;
			DualNode *n = new DualNode(data);
			p->next = n;
			n->pre = p;
			p = n;
		}
	}
	void dualBubbleSort()
	{
		// first是待排序区间的第一个节点 last是待排序的最后一个节点
		DualNode *p = head->next,*first=head->next,*last=head->next;
		// last走到链表最后一个节点
		while (last->next != nullptr)
			last = last->next;
		// 当链表中节点个数大于1时
		while (first!= last)
		{
			// 排序结束标志 待排区间尾在头之前
			if (last->next == first)
				break;
			// 从待排区间头开始依次向后比较
			while (p != last)
			{
				if (p->data > p->next->data)
					swap(p->data, p->next->data);
				p = p->next;
			}
			// 比较完成后最后一个数据到达了最终位置 将待排区间尾前移一个
			last = last->pre;
			p = last;
			// 排序结束标志
			if (last->next == first)
				break;
			// 从待排区间尾开始向前依次比较
			while (p != first)
			{
				if (p->data < p->pre->data)
					swap(p->data, p->pre->data);
				p = p->pre;
			}
			// 比较完成后第一个数据到达了最终位置 将待排区间头向后移一个
			first = first->next;
			p = first;
		}
	}
	void traverse()
	{
		DualNode *p = head->next;
		while (p->next != nullptr)
		{
			cout << p->data << ' ';
			p = p->next;
		}
		cout << p->data << endl;
	}
private:
	DualNode *head;
};

int main()
{
	int length;
	while (cin >> length && length != 0)
	{
		DualList L(length);
		L.dualBubbleSort();
		L.traverse();
	}
	system("pause");
	return 0;
}