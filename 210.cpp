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
			//bks = enlargeCapacity(bks, currentCapacity);
			Book *nbks = new Book[currentCapacity + 100];
			for (int j = 0; j < currentCapacity; j++)
				nbks[j] = bks[j];
			currentCapacity += 100;
			Book *p = bks;
			bks = nbks;
			delete[] p;
		}

		bks[curr++] = bk;
	}

	//读入要查找图书序号
	int searchNum;
	cin >> searchNum;
	int temp;
	int *searchIndexes = (int*)malloc(searchNum * sizeof(int));
	for (int i = 0; i < searchNum; i++)
	{
		cin >> temp;
		//searchIndexes[i] = (int)malloc(sizeof(int));
		searchIndexes[i] = temp-1;
	}

	//输出信息
	for (int j = 0; j < searchNum; j++)
	{
		if (count<=searchIndexes[j]||searchIndexes[j]<0)
			cout << "Sorry，the book on the best position doesn't exist!" << endl;
		else
		{
			cout << bks[searchIndexes[j]].sn << " " << bks[searchIndexes[j]].name << " " << setiosflags(ios::fixed) << setprecision(2) << bks[searchIndexes[j]].price << endl;
		}
	}

	//释放图书序号数组
	free(searchIndexes); 
    delete[] bks;

	system("pause");
	return 0;
}
