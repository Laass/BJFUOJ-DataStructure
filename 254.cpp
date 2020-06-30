#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
#define ERROR -127
#define OK 0

class Stack
{
public:
	Stack()
	{
		base = new char[initSize];
		top = base;
	}

	int push(char e)
	{
		if (top - base < initSize)
		{
			*top = e;
			top++;
			return OK;
		}
		return ERROR;
	}

	char pop()
	{
		if (top != base)
		{
			top--;
			return *top;
		}
		return ERROR;
	}

	char getTop()
	{
		if (top != base)
			return *(top - 1);
		else
			return ERROR;
	}
private:
	char *base;
	char *top;
	int initSize=50;
};

char precedence(char a, char b)
{
	if ((a == '('&&b == ')') || (a == '='&&b == '='))
		return '=';
	else if (a == '=' || a == '(' || b == '(' || ((a == '+' || a == '-') && (b == '*' || b == '/')))
		return '<';
	else
		return '>';
}

int main()
{
	char str[100];
	while (cin >> str && str[0] != '=')
	{
		Stack optr;
		optr.push('=');
		for (int i = 0; str[i] != '\0'; i++)
		{
			if ('0' <= str[i] && str[i] <= '9')
				cout << str[i];
			else
			{
				while (true)
				{
					if (precedence(optr.getTop(), str[i]) == '<')
					{
						optr.push(str[i]);
						break;
					}
					else if (precedence(optr.getTop(), str[i]) == '>')
						cout << optr.pop();
					else
					{
						optr.pop();
						break;
					}
				}
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}