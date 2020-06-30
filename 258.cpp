#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

void inverse(char *&str, int len)
{
	if (len == 1)
		return;
	else if (len == 2)
	{
		swap(str[0], str[1]);
		return;
	}
	else if (len == 3)
	{
		swap(str[0], str[2]);
		return;
	}
	else
	{
		swap(str[0], str[len - 1]);
		char *n = str;
		inverse(++n, len - 2);
	}
}

int main()
{
	char *str=new char[50];
	while (cin >> str && str[0] != '0')
	{
		inverse(str, strlen(str));
		for (int i = 0; str[i] != '\0'; i++)
			cout << str[i];
		cout << endl;
	}
	delete[]str;
	system("pause");
	return 0;
}