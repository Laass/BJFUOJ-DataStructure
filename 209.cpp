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

	//读入最爱图书信息
	int favNum;
	cin >> favNum;
	char temp[100];
	char **favNames = (char**)malloc(favNum * sizeof(char*));
	for (int i = 0; i < favNum; i++)
	{
		cin >> temp;
		favNames[i] = (char*)malloc(100 * sizeof(char));
		strcpy(favNames[i], temp);
	}

	//输出信息
	for (int j = 0; j < favNum; j++)
	{
		int currNum = 0;
		for (int i = 0; i < count; i++)
			if (strcmp(favNames[j], bks[i].name) == 0)
				currNum++;
		if (currNum == 0)
			cout << "Sorry，there is no your favourite!" << endl;
		else
		{
			cout << currNum << endl;
			for (int i = 0; i < count; i++)
				if (strcmp(favNames[j], bks[i].name) == 0)
					cout << bks[i].sn << " " << bks[i].name << " " << setiosflags(ios::fixed) << setprecision(2) << bks[i].price << endl;
		}
	}

	//释放最爱书名数组
	for (int i = 0; i < favNum; i++)
		free(favNames[i]);
	free(favNames);

	system("pause");
	return 0;
}
