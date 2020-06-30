#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

struct Node
{
	char data;
	Node *lchild, *rchild;

	Node()
	{
		data = '\0';
		lchild = rchild = nullptr;
	}

	Node(char ch)
	{
		data = ch;
		lchild = rchild = nullptr;
	}
};

class Tree
{
public:
	Tree()
	{
		this->root = new Node();
	}
	Tree(char *str)
	{
		content = str;
		p = 0;
		preOrderCreate(root);
	}

	bool identical(Tree T)
	{
		return match(this->root, T.root);
		
	}
private:
	Node *root;
	char *content;
	int p;
	void preOrderCreate(Node *&T)
	{
		if (content[p] == '0')
		{
			T = nullptr;
			p++;
		}
		else
		{
			T = new Node(content[p]);
			p++;
			preOrderCreate(T->lchild);
			preOrderCreate(T->rchild);
		}
	}
	bool match(Node *p, Node *q)
	{
		bool m = true;
		if (p!=nullptr&&q!=nullptr)
		{
			m=match(p->lchild, q->lchild);
			if (m)
				if (p->data != q->data)
					return false;
				else
					;
			if (m)
				m = match(p->rchild, q->rchild);
			return m;

		}
		if (p == nullptr&&q == nullptr)
			return true;
		return false;
	}
};
int main()
{
	char str[100];
	while (cin >> str && str[0] != '0')
	{
		Tree t1 = Tree(str);
		cin >> str;
		Tree t2 = Tree(str);
		if (t1.identical(t2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}