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
	LinkedList()
	{
		head = new Node();
	}
	LinkedList(int length)
	{
		head = new Node();
		Node *p = head;
		int data;
		while (length--)
		{
			cin >> data;
			Node *n = new Node(data);
			p->next = n;
			p = n;
		}
	}
	void oddEvenSplit()
	{
		int pos = 1;
		Node *oddHead = head;
		Node *evenHead = new Node();
		Node *p = head, *q = evenHead;
		while (p->next != nullptr)
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
	void insertHead(int data)
	{
		Node *n = new Node(data);
		n->next = head->next;
		head->next = n;
	}
	LinkedList add(LinkedList L)
	{   /*将本链表的每一位和L的每一位相加 结果存在result中
		链表按照从低位到高位顺序存数的每一位
		相加时每对应位相加 再加上前一位的进位 结果存在新链表中
		用尾插法将结果由低位到高位存在result中*/

		LinkedList result;
		Node *r = result.head;
		bool carry = false;  // 记录进位
		Node *p = head->next, *q = L.head->next;
		while (p != nullptr&&q != nullptr)  //当两链表有互相对应的节点时 
		{
			int num;

			if (carry)  // 如果有来自上一位的进位 则这位的值+1
				num = p->data + q->data + carry;
			else
				num = p->data + q->data;

			if (num > 9)  //如果这位加出来结果大于9 要进位
			{
				carry = true;  // 记进位
				Node *n = new Node(num - 10); //保存进位后值
				r->next = n;  // 用尾插法
				r = n;
			}
			else
			{
				carry = false;
				Node *n = new Node(num);
				r->next = n;
				r = n;
			}
			p = p->next;
			q = q->next;
		}
		if (p != nullptr)  // 如果p中还有数
		{
			while (p != nullptr)  // 把p中剩下的高位数存进result 
			{                     // 加上之前的进位后可能有进位
				int num;
				if (carry)  // p中数和进位加起来 
					num = p->data + 1;
				else
					num = p->data;
				if (num > 9)  // 如果进位了
				{
					carry = true;  // 记进位
					Node *n = new Node(num - 10);
					r->next = n;  // 尾插法保存到result中
					r = n;
				}
				else
				{
					carry = false;
					Node *n = new Node(num);
					r->next = n;
					r = n;
				}
				p = p->next;
			}

		}
		else if (q != nullptr)  // 如果q中还有数 操作和q中有数一样
		{
			while (q != nullptr)
			{
				int num;
				if (carry)
					num = q->data + 1;
				else
					num = q->data;
				if (num > 9)
				{
					carry = true;
					Node *n = new Node(num - 10);
					r->next = n;
					r = n;
				}
				else
				{
					carry = false;
					Node *n = new Node(num);
					r->next = n;
					r = n;
				}
				q = q->next;
			}
		}
		if (carry)  // 如果前面的相加结果有进位还没处理 则给结果最后加个1
		{
			Node *n = new Node(1);
			r->next = n;
			r = r->next;
		}
		return result;
	}
	void switchTwoNodePos(int length)
	{
		int switchTime = length / 2;
		Node *pre = head;
		for (int i = 0; i < switchTime; i++)
		{
			Node *groupNext=pre->next->next->next;
			Node *first = pre->next, *second = pre->next->next;
			pre->next = second;
			second->next = first;
			first->next = groupNext;
			pre = pre->next->next;
		}
	}
	void circularMoveRight(int moveTimes)
	{   // 所有节点右移moveTimes次
		// 通过所有节点左移实现
		int length = getLength();
		if (moveTimes > length)
			moveTimes = moveTimes % length;
		circularMoveLeft(length - moveTimes);
	}
	void circularMoveLeft(int moveTimes)
	{   // 所有节点左移moveTimes次
		// 也就是重复moveTimes次将首元节点接到链表结尾
		Node *tail = head;
		while (tail->next != nullptr)
			tail = tail->next;
		Node *p = head->next;
		while (moveTimes--)
		{
			head->next = p->next;
			tail->next = p;
			p->next = nullptr;
			tail = p;
			p = head->next;
		}
	}
private:
	Node *head;
};

int main()
{
	int length,moveTimes;
	while (cin >> length &&length != 0)
	{
		LinkedList list = LinkedList(length);
		cin >> moveTimes;
		list.circularMoveRight(moveTimes);
		list.traverse();
	}
	system("pause");
	return 0;
}