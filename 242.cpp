#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

#define ERROR -1
#define GOOD 0

class Stack
{
public:
	Stack()
	{
		base = new char[50];
		top = base;
	}

	int push(char e)
	{
		if (top - base < capacity)
		{
			*top = e;
			top++;
			return GOOD;
		}
		return ERROR;
	}

	char pop()
	{
		if (top != base)
		{
			top--;
			char e = *top;
			return e;
		}
		return ERROR;
	}

	char getTop()
	{
		if (top != base)
			return *(top - 1);
		return ERROR;
	}

private:
	char *base;
	char *top;
	int capacity = 50;
};

int main()
{
	char str[100];
	int length;
	while (cin >> str && str[0] != '0')
	{
		length = strlen(str);
		bool match = true;
		Stack s;
		int i;
		for (i = 1; i <= length / 2; i++)
			s.push(str[i - 1]);
		if (length % 2 == 0)
		{
			for (; i <= length; i++)
			{
				if (s.pop() != str[i - 1])
				{
					match = false;
					break;
				}
			}
		}
		else
		{
			i++;  //跳过中间的字符
			for (; i < length; i++)
			{
				if (s.pop() != str[i - 1])
				{
					match = false;
					break;
				}
			}
		}
		if (match)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}