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
		for (int i = 0; i < n - 1; i++)  // ��ǰ��n-1�� �ߵ��������ڵ�n���ڵ�ǰ
		{
			p = p->next;
			if (p == head)  // ����ߵ�ʱ�����ߵ���ͷ��� ������ͷ���
				p = p->next;
		}
		if (p->next == head)  // �ߵ���ͷ���ǰһ���ڵ� Ҫ�������ͷ����һ���ڵ� ����ǰ��һ��
			p = p->next;
		cout << p->next->data << " ";  // �����һ���ڵ���Ϣ
		q = p->next;  // ɾ����һ���ڵ�
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