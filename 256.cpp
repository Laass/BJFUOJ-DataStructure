#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
int m, n;
int BF(char s[], char p[])
{   //最普通的模式匹配  字符数组从1开始
	int i = 1, j = 1, t = 1;
	while (i <= m && j <= n)  //当两个数组都没有比对完时
	{
		if (s[i] == p[j])  //两个字符相同
		{
			i++;
			j++;
		}
		else  //两个字符不相同 则从头开始再比
		{
			i = ++t;
			j = 1;
		}
	}
	if (j > n)  //如果pattern串全部比完 说明有匹配
		return 1;
	else
		return 0;
}
int main()
{   //a是人DNA b是病毒DNA s是源串 p是模式串
	char a[MAX], b[MAX], s[MAX], p[MAX];
	while (cin >> b >> a && a[0] != '0'&&b[0] != '0')
	{
		int i, j, flag = 0;
		m = strlen(a);
		n = strlen(b);
		//把人DNA放到源串中 从第1个位置开始放 不从0开始
		for (i = 1; i <= m; i++)
			s[i] = a[i - 1];
		s[m + 1] = '\0';
		//把病毒DNA复制一遍放到原来的DNA后边
		for (i = n; i < 2 * n; i++)
			b[i] = b[i - n];
		b[2 * n] = '\0';
		//从病毒DNA的不同位置开始取长度为病毒DNA唱的的字符串 与人DNA比较
		//病毒DNA是环状的 这样可以把从任何位置开始的病毒DNA串比对一遍
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= n; j++)
				p[j] = b[i + j - 1];
			p[n + 1] = '\0';
			if (BF(s, p))
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}