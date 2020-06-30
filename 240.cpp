#include<iostream>
#include<cstdlib>
#include<iomanip>
#pragma warning(disable:4996)
using namespace std;

#define ERROR -2147483647

template <class T>
class Stack
{
public:
	T *base;
	T *top;

	Stack()
	{
		this->base = new T[this->stackSize];
		this->top = this->base;
	}

	int push(T e)
	{
		if (this->top - this->base < stackSize)
		{
			*this->top = e;
			this->top++;
			return 0;
		}
		return ERROR;
	}

	T pop()
	{
		if (this->top == this->base)
			return ERROR;
		return *--this->top;
	}

	T getTop()
	{
		if (this->top != this->base)
			return *(this->top - 1);
		return ERROR;
	}

private:
	static const int stackSize = 50;
};

double calc(double a, double b, char op)
{
	double result;
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
	return result;
}

char precedence(char a, char b)
{
	if ((a == '('&&b == ')') || (a == '='&&b == '='))
		return '=';
	else if (a == '(' || a == '=' || b == '(' || (a == '+' || a == '-') && (b == '*' || b == '/'))
		return '<';
	else
		return '>';
}

int main()
{
	char str[100];
	while (cin >> str && str[0] != '=')
	{
		Stack<char> optr;
		Stack<double> opnd;  //operand
		optr.push('=');
		int num = 0, e = 0;
		bool haveNum = false;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if ('0' <= str[i] && str[i] <= '9')  //如果读到的是数字
			{
				num = num * 10 + (str[i] - '0');
				haveNum = true;
				if (e != 0)  //小数点后有几位 拼出来的数最后就要除以10的几次方
					e = e * 10;
			}
			else if (str[i] == '.')
				e = 1;
			else //读到的是操作符
			{
				if (haveNum)  //有数需要入栈
				{
					double number = num;
					if (e != 0)
						number = number / e;
					opnd.push(number);
					num = e = 0;
					haveNum = false;
				}
				while (true)
				{
					if (precedence(optr.getTop(), str[i]) == '<')
					{   //如果栈顶操作符<读入操作符
						optr.push(str[i]);  //读入的操作符入栈
						break;
					}
					else if (precedence(optr.getTop(), str[i]) == '>')
					{   //如果栈顶操作符>读入操作符 要进行运算
						double a = opnd.pop();
						double b = opnd.pop();
						char op = optr.pop();
						opnd.push(calc(a, b, op));
					}
					else
					{  //如果栈顶操作符=读入操作符 是左右括号相遇了 都扔掉
						optr.pop();
						break;
					}
				}

			}

		}
		cout << setiosflags(ios::fixed) << setprecision(2) << opnd.pop() << endl;
	}
	system("pause");
	return 0;
}