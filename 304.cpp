#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

struct TNode
{
	int data;
	TNode *lchild, *rchild;
	TNode()
	{
		data = -1;
		lchild = rchild = nullptr;
	}
	TNode(int data)
	{
		this->data = data;
		lchild = rchild = nullptr;
	}
};
class Tree
{
public:
	Tree()
	{
		preOrderCreate(root);
	}
	int WPL()
	{
		wplValue = 0;
		if (root==nullptr||(root->lchild == nullptr&&root->rchild == nullptr))
			return -1;
		wpl(root,0);
		return wplValue;
	}
private:
	TNode *root;
	int data;
	int wplValue;
	void preOrderCreate(TNode *&T)
	{
		cin >> data;
		if (data != 0)
		{
			T = new TNode(data);
			preOrderCreate(T->lchild);
			preOrderCreate(T->rchild);
		}
		else
			T = nullptr;
	}
	void wpl(TNode *T, int level)
	{
		if (T != nullptr)
		{
			if (T->lchild == nullptr&&T->rchild == nullptr)
				wplValue += T->data*level;
			else
			{
				if (T->lchild != nullptr)
					wpl(T->lchild, level + 1);
				if (T->rchild != nullptr)
					wpl(T->rchild, level + 1);
			}
		}
	}
};
int main()
{
	while (true)
	{
		Tree t;
		int wplValue = t.WPL();
		if (wplValue != -1)
			cout << wplValue << endl;
		else
			break;
	}
	system("pause");
	return 0;
}