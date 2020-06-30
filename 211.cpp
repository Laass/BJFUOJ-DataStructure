#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#pragma warning(disable:4996)

using namespace std;

const int initSize = 100;

struct Book
{
	char sn[100];
	char name[100];
	float price;
};

Book parseBookInfo(char sn[], char name[],float price)
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
{
	Book *nbks = new Book[currentCapacity + 100];
	for (int j = 0; j < currentCapacity; j++)
		nbks[j] = bks[j];
	currentCapacity += 100;
	Book *p = bks;
	bks = nbks;
	delete[] p;
}

int insertToList(Book *&bks, int &count,int &currentCapacity,int pos, Book nbk)
{
	if (pos < 1 || count < pos)
	{
		cout << "Sorry，the position to be inserted is invalid!" << endl;
		return -1;
	}
	if (count + 1 > currentCapacity)
		enlargeCapacity(bks, currentCapacity);
	for (int i = count - 1; i >= pos - 1; i--)
		bks[i + 1] = bks[i];
	bks[pos - 1] = nbk;
	count++;
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
		{
			enlargeCapacity(bks, currentCapacity);
			/*Book *nbks = new Book[currentCapacity + 100];
			for (int j = 0; j < currentCapacity; j++)
				nbks[j] = bks[j];
			currentCapacity += 100;
			Book *p = bks;
			bks = nbks;
			delete[] p;*/
		}

		bks[curr++] = bk;
	}

	//读入要添加的图书序号
	int insertPos;
	cin >> insertPos;

	//读入新书信息
	cin >> sn;
	cin >> name;
	cin >> price;
	Book nbk = parseBookInfo(sn, name, price);

	//插入新书信息
	if (insertToList(bks, count, currentCapacity, insertPos, nbk) == -1)
		;
	else
	{
		//输出信息
		for (int j = 0; j < count; j++)
			cout << bks[j].sn << " " << bks[j].name << " " << setiosflags(ios::fixed) << setprecision(2) << bks[j].price << endl;
	}

	delete[]bks;

	system("pause");
	return 0;
}
