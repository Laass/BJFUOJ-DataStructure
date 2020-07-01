#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

const int MaxSize = 100;

int BF(char str[],char target[])
{
	int i = 0, j = 0;
	while (i <= strlen(str)-1 && j <= strlen(target)-1)
	{
		if(str[i]==target[j])
		{
			i++; 
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == strlen(target))
		return i - strlen(target);
	else
		return -1;
}

int main()
{
	char str[MaxSize],target[MaxSize];
	while (cin >> str >> target && strcmp(str,"0")!=0&& strcmp(target, "0") != 0)
	{
		int pos = BF(str, target);
		cout << pos << endl;
	}
	system("pause");
	return 0;
}