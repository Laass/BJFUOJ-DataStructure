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

class BList
{
public:
	BNode *head;  //有头结点
	int length;  //存储这个链表的长度

	BList()
	{
		this->head = new BNode();
		this->length= 0;
		this->tail = head;
	}

	void addToList(char sn[], char name[], float price)
	{   //尾插法
		BNode *bk = new BNode(sn, name, price);
		this->tail->next = bk;
		this->tail = bk;
		this->length++;
	}

	void traverseList()
	{//输出链表内容
		BNode *bk = this->head->next;
		while (bk != nullptr)
		{
			cout << bk->sn << " " << bk->name << " "
				<< setiosflags(ios::fixed) << setprecision(2) << bk->price << endl;
			bk = bk->next;
		}
	}

	float getAvgPrice()
	{//计算并返回平均价格
		calcAvgPrice();
		return this->avgPrice;
	}

	void alterPrice()
	{//修改所有书价格 <平均价格的提高10% 其他提高20%
		BNode *bk = this->head->next;
		while (bk != nullptr)
		{
			if (bk->price < this->avgPrice)
				bk->price *= 1.2;
			else
				bk->price *= 1.1;
			bk = bk->next;
		}
	}

private:
	BNode *tail;
	float avgPrice;

	void calcAvgPrice()
	{//计算平均价格
		float sum = 0;
		BNode *bk = this->head->next;
		while (bk != nullptr)
		{
			sum += bk->price;
			bk = bk->next;
		}
		this->avgPrice = sum / this->length;
	}
};

int main()
{
	char sn[100], name[100];
	float price;
	BList bList;

	//读入方式1 以0 0 0 
	//读入图书信息 尾插法创建链表
	cin >> sn >> name >> price;
	while (sn[0] != '0'&&name[0] != '0'&&price != 0.0)
	{
		bList.addToList(sn, name, price);
		cin >> sn >> name >> price;
	}

	float avgPrice = bList.getAvgPrice();
	bList.alterPrice();

	cout << setiosflags(ios::fixed) << setprecision(2) << avgPrice << endl;
	bList.traverseList();

	system("pause");
	return 0;
}
