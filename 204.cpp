#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#pragma warning(disable:4996)

using namespace std;

const int initSize = 10;

struct Book
{
	char sn[14];
	char name[30];
	float price;
};

Book parseBookInfo(char bookInfo[])
{
	int i;
	Book bk;
	char temp[30];

	//提取编号
	for (i = 0; bookInfo[i] != ' '; i++)
		temp[i] = bookInfo[i];
	temp[i] = '\0';
	strcpy(bk.sn, temp);
	memset(temp, '\0', sizeof(temp));
	i++;

	//提取书名
	int j;
	for (j = 0; bookInfo[i] != ' ';i++, j++)
		temp[j] = bookInfo[i];
	temp[j] = '\0';
	strcpy(bk.name, temp);
	memset(temp, '\0', sizeof(temp));
	i++;

	//提取价格
	int k;
	for (k = 0; i < strlen(bookInfo); i++,k++)
		temp[k] = bookInfo[i];
	temp[k] = '\0';
	bk.price = atof(temp);

	return bk;
}

int main()
{
	Book *bks=new Book[initSize];
	char bookInfo[45];
	int i = 0,currentCapacity= initSize;

	//读入信息
	cin.getline(bookInfo, 45);
	while (strcmp(bookInfo, "0 0 0") != 0&&strcmp(bookInfo,"")!=0)
	{
		Book bk = parseBookInfo(bookInfo);
		
		//如果数组不够大 则开新的大一倍的数组
		if (i == currentCapacity)
		{
			//bks = enlargeCapacity(bks, currentCapacity);
			Book *nbks = new Book[currentCapacity << 1 + 1];
			for (int j = 0; j < currentCapacity; j++)
				nbks[j] = bks[j];
			currentCapacity <<= 1;
			Book *p = bks;
			bks = nbks;
			delete[] p;
		}

		bks[i++] = bk;
		memset(bookInfo, '\0', sizeof(bookInfo));
		cin.getline(bookInfo, 45);
	}

	//输出信息
	cout << i << endl;
	for (int j = 0; j < i; j++)
		cout << bks[j].sn << " " << bks[j].name << " " << setiosflags(ios::fixed) << setprecision(2) << bks[j].price << endl;

	system("pause");
	return 0;
}
