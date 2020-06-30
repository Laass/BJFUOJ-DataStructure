#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{  // 每个位置的数和它后边的所有数比对
	int lines, cols;
	while (cin >> lines >> cols && lines != 0 && cols != 0)
	{  // 给数组开空间
		int **arr = (int**)malloc(lines * sizeof(int*));
		for (int i = 0; i < lines; i++)
		{
			arr[i] = (int*)malloc(cols * sizeof(int));
			memset(arr[i], 0, cols*sizeof(int));
		}
		for (int i = 0; i < lines; i++)
			for (int j = 0; j < cols; j++)
				cin >> arr[i][j];
		bool hasSame = false;
		for(int i=0;i<lines;i++)  // 每个数和后边的所有数比对
			for (int j = 0; j < cols; j++)
			{
				int a = arr[i][j];  // 当前用来比较的数
				for (int m = i; m < lines; m++)
				{
					int n;
					if (m == i)  // 如果现在所在的行是取出用来比较的数的行
						n = j+1;  // 则从用来比较的数后开始比 不比较一行里所有数
					else
						n = 0;  // 比较本行中所有数
					for (; n < cols; n++)
						if (a == arr[m][n])
							hasSame = true;
				}
			}
		if (hasSame)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		for (int i = 0; i < lines; i++)
			free(arr[i]);
		free(arr);
	}
	system("pause");
	return 0;
}