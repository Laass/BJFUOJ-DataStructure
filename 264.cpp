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

	void switchChild()
	{
		_switchChild(root);
	}

	void preOrderTraverse()
	{
		_preOrderTraverse(root);
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
		if (p != nullptr&&q != nullptr)
		{
			m = match(p->lchild, q->lchild);
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
	void _switchChild(Node *T)
	{
		if (T != nullptr)
		{
			swap(T->lchild, T->rchild);
			_switchChild(T->lchild);
			_switchChild(T->rchild);
		}
	}
	void _preOrderTraverse(Node *T)
	{
		if (T != nullptr)
		{
			cout << T->data;
			_preOrderTraverse(T->lchild);
			_preOrderTraverse(T->rchild);
		}
	}
};
int main()
{
	char str[100];
	while (cin >> str && str[0] != '0')
	{
		Tree t1 = Tree(str);
		t1.switchChild();
		t1.preOrderTraverse();
		cout << endl;
	}

	return 0;
}