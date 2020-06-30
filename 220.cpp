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

	BNode(BNode *bk)
	{
		strcpy(this->sn, bk->sn);
		strcpy(this->name, bk->name);
		this->price = bk->price;
		next = nullptr;
	}

	void showBookInfo()
	{
		cout << this->sn << " " << this->name << " "
			<< setiosflags(ios::fixed) << setprecision(2) << this->price << endl;
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
		this->length = 0;
		this->tail = head;
	}

	void addToList(char sn[], char name[], float price)
	{   //尾插法
		BNode *bk = new BNode(sn, name, price);
		this->tail->next = bk;
		this->tail = bk;
		this->length++;
	}

	void addToList(BNode *bk)
	{
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

	void insertAfterHead(BNode *bk)
	{//头插法
		BNode *p = this->head->next;
		this->head->next = bk;
		bk->next = p;
	}

	void invertList()
	{
		BNode *p = this->head->next, *t;

		//断开头结点和后边的连接
		//如果不断开头结点和后边的连接的话 转换完后 最后一个节点的next会指向自己
		this->head->next = nullptr;

		for (int i = 0; i < this->length; i++)
		{
			t = p->next;
			insertAfterHead(p);
			p = t;
		}
	}

	void showDearestBooks()
	{
		//计算最贵价格
		this->highestPrice = 0.0;
		BNode *bk = this->head->next;
		while (bk != nullptr)
		{
			if (this->highestPrice < bk->price)
				this->highestPrice = bk->price;
			bk = bk->next;
		}

		//记录最贵图书信息
		BList dList;
		bk = this->head->next;
		while (bk != nullptr)
		{
			if (this->highestPrice == bk->price)
			{
				BNode *nbk = new BNode(bk);
				dList.addToList(nbk);
			}
			bk = bk->next;
		}

		//输出最贵图书信息
		cout << dList.length << endl;
		dList.traverseList();
	}

	BList searchByName(char target[])
	{
		BList targetList;//存储搜索到的图书信息 可能有多个

		BNode *bk = this->head->next;
		while (bk != nullptr)
		{
			if (strcmp(bk->name, target) == 0)
				targetList.addToList(new BNode(bk));
			bk = bk->next;
		}
		return targetList;
	}

	BNode* bNodeAt(int index)
	{
		if (index <= 0 || this->length < index)//如果寻找的位置超过图书个数
			return nullptr;

		int i = 0;
		BNode *bk = this->head;
		while (i < index)
		{
			bk = bk->next;
			i++;
		}
		return new BNode(bk);
	}

private:
	BNode *tail;
	float avgPrice;
	float highestPrice;

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
	
	//读入方式1 以0 0 0结束
	//读入图书信息 尾插法创建链表
	/*cin >> sn >> name >> price;
	while (sn[0] != '0'&&name[0] != '0'&&price != 0.0)
	{
		bList.addToList(sn, name, price);
		cin >> sn >> name >> price;
	}*/

	//读入方式二 第一行为图书数量 后n行为图书信息
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> sn >> name >> price;
		bList.addToList(sn, name, price);
	}

	//读入要查找的图书信息
	cin >> num;
	int *indexes = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
		cin >> indexes[i];
	
	//查找并输出
	for (int i = 0; i < num; i++)
	{
		BNode *bk = bList.bNodeAt(indexes[i]);
		if (bk == nullptr)
			cout << "Sorry，the book on the best position doesn't exist!" << endl;
		else
			bk->showBookInfo();
	}

	system("pause");
	return 0;
}
