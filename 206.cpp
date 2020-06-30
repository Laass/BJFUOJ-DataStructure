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
	int count = 0, currentCapacity = initSize;

	//读入信息
	cin >> sn;
	cin >> name;
	cin >> price;
	while (strcmp(sn, "0") != 0 && strcmp(name, "0") != 0 && strcmp(price, "0") != 0)
	{
		Book bk = parseBookInfo(sn, name, price);

		//如果数组不够大 则开新的大一些的数组
		if (count == currentCapacity)
		{
			//bks = enlargeCapacity(bks, currentCapacity);
			Book *nbks = new Book[currentCapacity + 10];
			for (int j = 0; j < currentCapacity; j++)
				nbks[j] = bks[j];
			currentCapacity += 10;
			Book *p = bks;
			bks = nbks;
			delete[] p;
		}

		bks[count++] = bk;
		memset(sn, '\0', sizeof(sn));
		memset(name, '\0', sizeof(name));
		memset(price, '\0', sizeof(price));
		cin >> sn;
		cin >> name;
		cin >> price;
	}

	//改变价格
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += bks[i].price;
	float avg = sum / (float)count;
	for (int i = 0; i < count; i++)
		if (bks[i].price < avg)
			bks[i].price *= 1.2;
		else
			bks[i].price *= 1.1;


	//输出信息
	cout << setiosflags(ios::fixed) << setprecision(2) << avg << endl;
	for (int j = 0; j < count; j++)
		cout << bks[j].sn << " " << bks[j].name << " " << setiosflags(ios::fixed) << setprecision(2) << bks[j].price << endl;

	system("pause");
	return 0;
}
