#include<iostream>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

#define ERROR -2147483647

class DblStack
{
public:
	int top[2];
	int bot[2];

	DblStack(int capacity)
	{
		this->data = new int[capacity];
		this->capacity = capacity;
		top[0] = -1;  //top[0]指向栈顶数据 top[0]=-1时为空
		top[1] = capacity;  //top[1]指向栈顶数据 top[0]=capacity时为空
		bot[0] = 0;  //data[0]是0号栈的栈底
		bot[1] = capacity - 1;  //data[capacity-1]是1号栈的栈底
	}

	bool s0Empty()
	{
		return top[0] < bot[0];
	}

	bool s1Empty()
	{
		return top[1] > bot[1];
	}

	bool full()
	{
		return top[0] + 1 == top[1];
	}

	int s0Push(int e)
	{
		if (!full())
		{
			top[0]++;
			data[top[0]] = e;
			return 0;
		}
		return ERROR;
	}

	int s1Push(int e)
	{
		if (!full())
		{
			top[1]--;
			data[top[1]] = e;
			return 0;
		}
		return ERROR;
	}

	int s0Pop()
	{
		if (!s0Empty())
		{
			int e = data[top[0]];
			top[0]--;
			return e;
		}
		return ERROR;
	}

	int s1Pop()
	{
		if (!s1Empty())
		{
			int e = data[top[1]];
			top[1]++;
			return e;
		}
		return ERROR;
	}


private:
	int *data;
	int capacity;
};

int main()
{
	int capacity, pushA, pushB,popA,popB,data;
	
	while (cin >> capacity && capacity != 0)
	{
		DblStack s(capacity);
		cin >> pushA >> pushB>>popA>>popB;
		while (pushA--)
		{
			cin >> data;
			s.s0Push(data);
		}
		while (pushB--)
		{
			cin >> data;
			s.s1Push(data);
		}

		cout << s.full() << endl;
		while (popA--)
		{
			cout << s.s0Pop() << " ";
		}
		cout << !s.s0Empty() << endl;
		while (popB--)
		{
			cout << s.s1Pop() << " ";
		}
		cout << !s.s1Empty() << endl;
	}
	system("pause");
	return 0;
}