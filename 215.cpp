#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#pragma warning(disable:4996)

using namespace std;

struct BNode
{
	char sn[100];
	char name[100];
	float price;
	BNode *next;

	BNode()
	{
		memset(sn, '\0', 100 * sizeof(char));
		memset(name, '\0', 100 * sizeof(char));
		price = -1.0;
		next = nullptr;
	}

	BNode(char sn[], char name[], float price)
	{
		strcpy(this->sn, sn);
		strcpy(this->name, name);
		this->price = price;
		next = nullptr;
	}

};

BNode parseBookInfo(char sn[], char name[], float price)
{
	BNode bk;
	strcpy(bk.sn, sn);
	strcpy(bk.name, name);
	bk.price = price;
	return bk;
}

void traverseList(BNode *head)
{//输出链表内容
	BNode *bk = head->next;
	while (bk != nullptr)
	{
		cout << bk->sn << " " << bk->name << " "
			<< setiosflags(ios::fixed) << setprecision(2) << bk->price << endl;
		bk = bk->next;
	}
}

void swapNodeInfo(BNode *&a, BNode *&b)
{//交换两个节点的信息
	char snTemp[100], nameTemp[100];
	float priceTemp;

	strcpy(snTemp, a->sn);
	strcpy(nameTemp, a->name);
	priceTemp = a->price;

	strcpy(a->sn, b->sn);
	strcpy(a->name, b->name);
	a->price = b->price;

	strcpy(b->sn, snTemp);
	strcpy(b->name, nameTemp);
	b->price = priceTemp;
}

BNode* nodeAt(BNode *head, int pos)
{//取某个位置的节点
	BNode *p = head->next;
	int i = 0;
	if (pos > (int)head->price - 1)
		return nullptr;
	while (i < pos)
	{
		p = p->next;
		i++;
	}
	return p;
}

void bubbleSort(BNode *&head)
{//对图书链表进行冒泡排序
	BNode *p = head->next;
	int num = (int)head->price;
	for(int i=0;i<num;i++)
		for (int j = 0; j < num - i - 1; j++)
		{
			BNode *a = nodeAt(head, j);
			BNode *b = nodeAt(head, j + 1);
			if (a->price < b->price)
				swapNodeInfo(a, b);
		}

}

int main()
{
	char sn[100], name[100];
	float price;
	BNode *head=new BNode();
	BNode *tail = head;
	head->price = 0;//用头结点的price存储这个链表的长度

	//读入图书信息 尾插法创建链表
	cin >> sn >> name >> price;
	while (sn[0] != '0'&&name[0] != '0'&&price != 0.0)
	{
		BNode *bk = new BNode(sn, name, price);
		tail->next = bk;
		tail = bk;
		head->price++;
		cin >> sn >> name >> price;
	}

	//排序
	bubbleSort(head);

	//输出图书信息
	traverseList(head);

	system("pause");
	return 0;
}