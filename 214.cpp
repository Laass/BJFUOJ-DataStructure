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

int main()
{
	char sn[100], name[100];
	float price;
	BNode head;
	BNode *tail=&head;
	head.price = 0;//用头结点的price存储这个链表的长度

	//读入图书信息 尾插法创建链表
	cin >> sn >> name >> price;
	while (sn[0] != '0'&&name[0] != '0'&&price != 0.0)
	{
		BNode *bk = new BNode(sn, name, price);
		tail->next = bk;
		tail = bk;
		head.price++;
		cin >> sn >> name >> price;
	}

	//输出图书信息
	cout << setprecision(0) << head.price << endl;
	traverseList(&head);
	system("pause");
	return 0;
}