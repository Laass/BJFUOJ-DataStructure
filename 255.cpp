#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int **map;
int exitNum;
bool out = false;

void maze(int startLine)
{
	for(int i=0;i<3;i++)
		if (map[startLine][i] != 0)
		{
			int num = map[startLine][i];
			if (num == exitNum)
			{
				out = true;
				return;
			}
			else
				maze(num);
		}
}

int main()
{
	map = (int**)malloc(101 * sizeof(int*));
	for (int i = 0; i < 101; i++)
		map[i] = (int*)malloc(3 * sizeof(int));
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 1; i <= n; i++)
		{
			memset(map[i], 0, 3 * sizeof(int));
			for (int j = 0; j < 3; j++)
				cin >> map[i][j];
		}
		cin >> exitNum;
		maze(1);
		if (out)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		out = false;
	}
	for (int i = 0; i < 101; i++)
		free(map[i]);
	free(map);
	system("pause");
	return 0;
}