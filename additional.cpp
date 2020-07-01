#include<iostream>
#include<cstdlib>
using namespace std;
// 自己加的题 2019年复试第四题 二叉树两节点的最近公共祖先
struct Node
{
	char data;
	Node *lchild, *rchild;
	Node()
	{
		data = '\0';
		lchild = rchild = nullptr;
	}
	Node(char data)
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
	void inOrderTraverse()
	{
		_inOrderTraverse(root);
	}
	Node* lowestCommonAncestor(char data1, char data2)
	{
		return LCA(root, data1, data2);
	}
private:
	Node *root;
	void preOrderCreate(Node *&T)
	{
		char data;
		cin >> data;
		if (data == '#')
			T = nullptr;
		else
		{
			T = new Node(data);
			preOrderCreate(T->lchild);
			preOrderCreate(T->rchild);
		}
	}
	void _inOrderTraverse(Node *T)
	{
		if (T != nullptr)
		{
			_inOrderTraverse(T->lchild);
			cout << T->data;
			_inOrderTraverse(T->rchild);
		}
	}
	Node* LCA(Node *root, char data1, char data2)
	{
		if (root == nullptr)
			return nullptr;
		if (root->data == data1 || root->data == data2)
			return root;
		Node *lResult = LCA(root->lchild, data1, data2);
		Node *rResult = LCA(root->rchild, data1, data2);
		if (lResult != nullptr&&rResult != nullptr)
			return root;
		else
			return lResult != nullptr ? lResult : rResult;
	}
};

int main()
{
	Tree tree;
	tree.inOrderTraverse();
	cout << endl;
	cout << tree.lowestCommonAncestor('B', 'E')->data << endl;
	system("pause");
	return 0;
}