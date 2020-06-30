#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)

using namespace std;

class Stack
{
public:
	Stack()
	{
		base = new int[stackSize];
		top = base;
	}

	int push(int e)
	{
		if (base - top < stackSize)
		{
			*top = e;
			top++;
			return 0;
		}
		else
			return -1;
	}

	int pop()
	{
		if (base != top)
		{
			top--;
			int e = *top;
			return e;
		}
		else
		{
			cout << "POP ERROR" << endl;
			return -1;
		}
	}

private:
	int *base;
	int *top;
	int stackSize = 50;
};

int main()
{
	int length,data;
	while (cin >> length && length != 0)
	{
		Stack s;
		while (length--)
		{
			cin >> data;
			if (data != -1)
				s.push(data);
			else
			{
				int e = s.pop();
				if (e == -1)
				{
					while (length--)
						cin >> data;
					//cin >> length;
					break;
				}
				else
					cout << e << endl;
			}
		}
	}
	system("pause");
	return 0;
}