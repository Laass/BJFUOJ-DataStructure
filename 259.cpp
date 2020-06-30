#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

void insert(char *s, char *t, int pos)
{
	int sLen, tLen,i;
	for (i = 0; s[i] != '\0'; i++)
		;
	sLen = i;
	for (i = 0; t[i] != '\0'; i++)
		;
	tLen = i;
	for (int j = sLen - 1; j >= pos - 1; j--)
		s[j + tLen] = s[j];
	for (int k = 0; k < tLen; k++)
		s[k + pos - 1] = t[k];
	s[sLen + tLen] = '\0';
}

int main()
{
	int pos;
	char s[50], t[50];
	while (cin >> pos && pos != 0)
	{
		cin >> s >> t;
		insert(s, t, pos);
		for (int i = 0; s[i] != '\0'; i++)
			cout << s[i];
		cout << endl;
	}
	system("pause");
	return 0;
}