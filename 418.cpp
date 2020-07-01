#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

const int MaxSize = 100;

int main()
{
	int length, data;
	bool exist[MaxSize],haveEmpty,first;
	while (cin >> length && length != 0)
	{
		memset(exist, false, MaxSize * sizeof(bool));
		first = true;  // 记录是否是第一个缺失的数字 控制输出格式（空格）用
		haveEmpty = false;  // 记录是否有缺失数字
		for (int i = 0; i < length; i++)  // 读输入数据
		{
			cin >> data;
			exist[data] = true;
		}
		int j;
		for (j = 1; j <= length; j++)
			if (exist[j] == false)
			{
				if (first)
				{
					cout << j;
					first = false;
					haveEmpty = true;
				}
				else
				{
					cout << " " << j;
					haveEmpty = true;
				}
			}
		if (haveEmpty == false)
			cout << "Not Found" << endl;
		else
			cout << endl;
	}
	system("pause");
	return 0;
}