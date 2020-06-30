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
		this->data = 0;
		this->next = nullptr;
	}

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

void initList(Node *&list,int n)
{
	Node *head = new Node();;
	Node *p = head;
	for (int i = 1; i <= n; i++)  
	{
		Node *n = new Node(i);
		p->next = n;
		p = n;
		head->data++;
	}
	p->next = head;
	list = head;
}

int getKing(Node *&head,int n)
{
	Node *p = head,*q;
	while (head->data>1)
	{
		for (int i = 0; i < n - 1; i++)  // 往前走n-1步 走到往后数第第n个节点前
		{
			p = p->next;
			if (p == head)  // 如果走的时候发现走到了头结点 则跳过头结点
				p = p->next;
		}
		if (p->next == head)  // 走到了头结点前一个节点 要输出的是头结点后一个节点 再往前走一步
			p = p->next;
		cout << p->next->data << " ";  // 输出后一个节点信息
		q = p->next;  // 删除后一个节点
		p->next = q->next;
		delete q;
		head->data--;
	}
	return head->next->data;
}

int main()
{
	int length,step;
	cin >> length >> step;
	Node *list;
	while (length != 0 && step != 0)
	{
		initList(list,length);
		int king = getKing(list, step);
		cout << king << endl;
		cin >> length >> step;
	}
	system("pause");
	return 0;
}