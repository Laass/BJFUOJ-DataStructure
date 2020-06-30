#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>

using namespace std;

const int initSize = 100;

struct Book
{
	char sn[100];
	char name[100];
	float price;
};

Book parseBookInfo(char sn[], char name[], float price)
{
	Book bk;

	//提取编号
	strcpy(bk.sn, sn);

	//提取书名
	strcpy(bk.name, name);

	//提取价格
	bk.price = price;

	return bk;
}

void enlargeCapacity(Book *&bks, int &currentCapacity)
{//扩大数组空间
	Book *nbks = new Book[currentCapacity + 100];//开个大点的数组
	for (int j = 0; j < currentCapacity; j++)//原数组内容移到新数组
		nbks[j] = bks[j];
	currentCapacity += 100;
	Book *p = bks;
	bks = nbks;
	delete[] p;//释放原数组空间
}


void reduceCapacity(Book *&bks, int count, int &currentCapacity)
{//减小数组容量 每次-100
	Book *nbks = new Book[currentCapacity - 100];//开个小一些的数组
	currentCapacity -= 100;
	for (int j = 0; j < currentCapacity; j++)//原数组内容移到新数组
		nbks[j] = bks[j];
	Book *p = bks;
	bks = nbks;
	delete[] p;//回收原数组空间
}

int delFromList(Book *&bks, int &count, int &currentCapacity, int pos)
{//从列表中删除图书信息
	if (pos < 1 || count < pos)//判断删除位置是否合理
	{
		cout << "Sorry，the position to be deleted is invalid!" << endl;
		return -1;
	}
	for (int i = pos - 1; i < count - 1; i++)//删除位置之后的图书信息前移
		bks[i] = bks[i + 1];
	count--;
	if (count < currentCapacity - 100)//如果图书信息较少 则换个小的数组
		reduceCapacity(bks, count, currentCapacity);
	return 0;
}

int main()
{
	Book *bks = new Book[initSize];
	char sn[20], name[35];
	float price;
	int count, curr = 0, currentCapacity = initSize;

	//读入图书信息
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> sn;
		cin >> name;
		cin >> price;

		Book bk = parseBookInfo(sn, name, price);

		//如果数组不够大 则开新的大一些的数组
		if (curr == currentCapacity)
			enlargeCapacity(bks, currentCapacity);

		bks[curr++] = bk;
	}

	//读入要删除的图书序号
	int delPos;
	cin >> delPos;

	//删除图书信息
	if (delFromList(bks, count, currentCapacity, delPos) == -1)//删除位置错误
		;
	else
	{
		//输出信息
		for (int j = 0; j < count; j++)
			cout << bks[j].sn << " " << bks[j].name << " " << setiosflags(ios::fixed) << setprecision(2) << bks[j].price << endl;
	}

	//回收图书信息数组空间
	delete[]bks;

	return 0;
}