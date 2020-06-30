#include<iostream>
#include<cstring>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

#define MaxSize 100

void sortStones(char stones[], int length)
{
	int i, j = 0, k = length - 1;
	for (i = 0; i < length; i++)
	{
		if (stones[i] == 'R')
		{
			// 从上次找的结尾开始找第一个不是R的字符
			while (stones[j] == 'R'&&i > j)
				j++;
			// 因为R优先级最高 所以找把不是R的字符往后换
			swap(stones[i], stones[j]);
			// 如果是把B换到了后边 可能还要把B往后换
			if (stones[i] == 'B')
				i--;
		}
		else if (stones[i] == 'B')
		{
			// 从尾开始找第一个不是B的字符
			while (stones[k] == 'B'&&i < k)
				k--;
			// 因为B的优先级最低 所以把B往后换
			swap(stones[i], stones[k]);
			// 如果是把R换到了前面 可能要把R继续往前换
			if (stones[i] == 'R')
				i--;
		}
	}
}

int main()
{
	int length;
	char stones[MaxSize];
	memset(stones, '\0', MaxSize * sizeof(char));
	while (cin >> length && length != 0)
	{
		for (int i = 0; i < length; i++)
			cin >> stones[i];
		sortStones(stones, length);
		for (int i = 0; i < length - 1; i++)
			cout << stones[i] << " ";
		cout << stones[length - 1] << endl;
	}
	system("pause");
	return 0;
}