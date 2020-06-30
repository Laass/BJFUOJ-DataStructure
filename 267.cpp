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

	void dblOrderTraverse()
	{
		_dblOrderTraverse(root);
	}

	int maxWidth()
	{
		memset(width, 0, 100 * sizeof(int));
		maxWidthRecord = 1;
		widthDFS(root, 1);
		return maxWidthRecord;
	}

	void firstDeepestPath()
	{
		len = 0;
		memset(temp, '\0', 100 * sizeof(char));
		memset(path, '\0', 100 * sizeof(char));
		DFS(root, len);
		cout << len << endl;
		for (int i = 0; i < len; i++)
			cout << path[i];
		cout << endl;
	}
private:
	Node *root;
	char *content;
	int p;
	int width[100];
	int maxWidthRecord;
	int len;  //记录最深层数
	char temp[100];  //暂存最长路径
	char path[100];  //保存最长路径
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
	void _dblOrderTraverse(Node *T)
	{
		if (T != nullptr)
		{
			cout << T->data;
			_dblOrderTraverse(T->lchild);
			cout << T->data;
			_dblOrderTraverse(T->rchild);
		}
	}
	void widthDFS(Node *T, int n)
	{
		if (T != nullptr)
		{
			width[n]++;
			maxWidthRecord = maxWidthRecord > width[n] ? maxWidthRecord : width[n];
			widthDFS(T->lchild, n + 1);
			widthDFS(T->rchild, n + 1);
		}
	}
	void DFS(Node *T, int n)
	{
		if (T != nullptr)
		{
			temp[n] = T->data;  //更新当前节点的字符
			if (T->lchild == nullptr&&T->rchild == nullptr)  //如果碰到叶子节点
			{
				if (n + 1 > len)  //如果到这个节点的深度大于当前已知的最大深度
				{
					len = n + 1;  //更新深度
					for (int i = 0; i <= n; i++)
						path[i] = temp[i];  //更新最深路径
				}
			}
			else
			{
				DFS(T->lchild, n + 1);
				DFS(T->rchild, n + 1);
			}
		}
	}
};
int main()
{
	char str[100];
	while (cin >> str && str[0] != '0')
	{
		Tree t1 = Tree(str);
		t1.firstDeepestPath();
	}
	system("pause");
	return 0;
}