#include<iostream>
#include<cstdlib>
#include<iomanip>
#pragma warning(disable:4996)
using namespace std;

#define GOOD 0
#define ERROR -1

class Stack
{
public:
	Stack()
	{
		base = new double[stackSize];
		top = base;
	}

	int push(double e)
	{
		if (top - base < stackSize)
		{
			*top = e;
			top++;
			return GOOD;
		}
		return ERROR;
	}

	double pop()
	{
		if (top != base)
		{
			top--;
			double e = *top;
			return e;
		}
		return ERROR;
	}

private:
	double *base;
	double *top;
	static const int stackSize = 50;
};

int main()
{
	char str[100];
	while (cin.getline(str,100) && str[0] != '=')
	{
		Stack opnd;
		double result;
		int num = 0, e = 0;
		bool haveNum = false;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if ('0' <= str[i] && str[i] <= '9')
			{
				num = num * 10 + (str[i] - '0');
				if (e != 0)
					e *= 10;
				haveNum = true;
			}
			else if (str[i] == '.')
				e = 1;
			else
			{
				if (haveNum)
				{
					double number = num;
					if (e != 0)
						number /= e;
					opnd.push(number);
					num = e = 0;
					haveNum = false;
				}
				if (str[i] == ' '||str[i]=='=')
					continue;
				char op = str[i];
				double a = opnd.pop(), b = opnd.pop();
				switch (op)
				{
				case '+':
					result = b + a;
					break;
				case '-':
					result = b - a;
					break;
				case '*':
					result = b * a;
					break;
				case '/':
					result = b / a;
					break;
				default:
					result = 0;
					break;
				}
				opnd.push(result);
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << opnd.pop() << endl;
	}
	system("pause");
	return 0;
}