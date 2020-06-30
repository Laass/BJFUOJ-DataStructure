#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#pragma warning(disable:4996)

using namespace std;

const int initSize = 100;

struct Book
{
	char sn[1000];
	char name[1000];
	float price;
};

Book parseBookInfo(char sn[], char name[], char price[])
{
	Book bk;

	//提取编号
	strcpy(bk.sn, sn);

	//提取书名
	strcpy(bk.name, name);

	//提取价格
	bk.price = atof(price);

	return bk;
}

int main()
{
	Book *bks = new Book[initSize];
	char sn[20], name[35], price[10];
	int count, curr = 0, currentCapacity = initSize;

	//读入信息
	cin >> count;
	for(int i=0;i<count;i++)
	{
		cin >> sn;
		cin >> name;
		cin >> price;

		Book bk = parseBookInfo(sn, name, price);

		//如果数组不够大 则开新的大一些的数组
		if (curr == currentCapacity)
		{
			//bks = enlargeCapacity(bks, currentCapacity);
			Book *nbks = new Book[currentCapacity+100];
			for (int j = 0; j < currentCapacity; j++)
				nbks[j] = bks[j];
			currentCapacity += 100;
			Book *p = bks;
			bks = nbks;
			delete[] p;
		}

		bks[curr++] = bk;
	}

	//逆序存储
	for (int i = 0; i < count / 2; i++)
	{
		Book bk;
		bk = bks[count-i-1];
		bks[count-i-1] = bks[i];
		bks[i] = bk;
	}


	//输出信息
	for (int j = 0; j < count; j++)
		cout << bks[j].sn << " " << bks[j].name << " " << setiosflags(ios::fixed) << setprecision(2) << bks[j].price << endl;

	system("pause");
	return 0;
}
