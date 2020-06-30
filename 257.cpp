#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

//0~9  48~57
//A~Z  65~90
//const int maxNum = 91;
//
//int main()
//{
//	char str[50];
//	int freq[maxNum];
//	memset(freq, 0, maxNum*sizeof(int));
//	while (cin >> str && str[0] != '0')
//	{
//		int len = strlen(str);
//		for (int i = 0; i < len; i++)
//		{
//			int pos = (int)str[i];
//			freq[pos]++;
//		}
//	}
//	for (int j = 48; j <= 57; j++)
//	{
//		if (freq[j] > 0)
//		{
//			char ch = (char)j;
//			cout << ch << ":" << freq[j] << endl;
//		}
//	}
//	for (int k = 65; k <= 90; k++)
//	{
//		if (freq[k] > 0)
//		{
//			char ch = (char)k;
//			cout << ch << ":" << freq[k] << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int i;
	char a[37];
	int  b[37];
	char c[100];
	while (cin >> c && c[0] != '0')
	{
		a[1] = 48; b[1] = 0;
		a[11] = 65; b[11] = 0;
		for (i = 2; i <= 10; i++)
		{
			a[i] = a[i - 1] + 1;
			b[i] = 0;
		}
		for (i = 12; i <= 36; i++)
		{
			a[i] = a[i - 1] + 1;
			b[i] = 0;
		}
		for (i = 1; i <= 36; i++)
			for (int j = 0; c[j] != '\0'; j++)
				if (a[i] == c[j])
					b[i]++;
		for (i = 1; i <= 11; i++)
			if (b[i] > 0)
				cout << a[i] << ":" << b[i] << endl;
		for (i = 12; i <= 36; i++)
			if (b[i] > 0)
				cout << a[i] << ":" << b[i] << endl;
	}
	system("pause");
	return 0;
}