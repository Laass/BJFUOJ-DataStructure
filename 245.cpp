#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)

using namespace std;

//int main()
//{
//	char str[100];
//	while (cin.getline(str, 100) && str[0] != '0')
//	{
//		int num = 0;
//		for (int i = 0; i < strlen(str); i++)
//		{
//			if (str[i] == '\0')
//				break;
//			if (str[i] == 'I')
//				num++;
//			else if (str[i] == 'O')
//				num--;
//		}
//		if (num == 0)
//			cout << "TRUE" << endl;
//		else
//			cout << "FALSE" << endl;
//	}
//	system("pause");
//	return 0;
//}

struct LSNode
{
	int data;
	struct LSNode *next;

	LSNode()
	{
		data = 0;
		next = nullptr;
	}

	LSNode(int data)
	{
		this->data = 0;
		this->next = nullptr;
	}
};

class LinkedStack
{
public:
	LinkedStack()
	{
		head = nullptr;
	}

	void push(int data)
	{
		LSNode *p = new LSNode(data);
		p->next = head;
		head = p;
	}

	int pop()
	{
		if (!empty())
		{
			LSNode *q = head;
			head = head->next;
			int e = q->data;
			delete q;
			return e;
		}
		return -1;
	}

	bool empty()
	{
		return head == nullptr;
	}

private:
	LSNode *head;
};

int main()
{
	char str[100];
	while (cin >> str && str[0] != '0')
	{
		LinkedStack s;
		bool correct = true;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == 'I')
				s.push(rand() % 100);
			else if (str[i] == 'O')
			{
				if (s.empty())
				{
					correct = false;
					break;
				}
				else
					s.pop();
			}
		}
		if (correct&&s.empty())
			cout << "TRUE" << endl;
		else
			cout << "FALSE"<<endl;
	}
	system("pause");
	return 0;
}