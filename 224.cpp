#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef struct PNode
{
	double a;  //系数
	int x;  //次数
	struct PNode* next;
}*Polynomial, PNode;

void CreatePolynomial(Polynomial& L, int n)
{// 读入多项式
	L = new PNode;
	L->next = NULL;

	for (int i = 0; i < n; i++) 
	{
		PNode* s = new PNode;
		cin >> s->a >> s->x;  //读入这项的系数 次数
		PNode* pre = L;
		PNode* cur = L->next;
		//按指数从大到小存多项式
		while (cur && s->x < cur->x)
		{
			pre = cur;
			cur = cur->next;
		}
		s->next = cur;
		pre->next = s;
	}
}

void OutputPolynomial(Polynomial L)
{
	if (!L || !L->next) 
	{
		cout << 0 << endl;
		return;
	}

	PNode* p = L->next;
	while (p)
	{
		if (p == L->next)  //如果是第一项
		{
			if (p->x != 0)
				cout << p->a << "x^" << p->x;
			else
				cout << p->a;
		}
		else //如果不是第一项 则要输出+
		{
			if (p->a > 0)
				cout << "+";
			if (p->x != 0) //如果系数不是0
				cout << p->a << "x^" << p->x;
			else
				cout << p->a;
		}
		p = p->next;
	}
	cout << endl;
}

Polynomial Add(Polynomial L1, Polynomial L2)
{
	PNode* p1 = L1->next;
	PNode* p2 = L2->next;
	PNode* r = NULL;

	Polynomial L3;  //存储相加结果
	CreatePolynomial(L3, 0);
	PNode* p3 = L3;

	while (p1 && p2) //当两个多项式都没遍历完
	{
		if (p1->x == p2->x)  //如果两项次数相同
		{
			int sum = p1->a + p2->a;  //系数相加
			if (sum) //系数相加后不为0
			{
				p1->a = sum;  //把p1的系数改为sum 接到L3上
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				p2 = p2->next;
			}
			else  //系数相加后为0
			{
				p1 = p1->next;
				p2 = p2->next;
			}

		}
		else if (p1->x > p2->x) //p1的次数高于p2
		{
			p3->next = p1;  //p1接到L3上
			p3 = p1;
			p1 = p1->next;
		}
		else  //p2的次数高于p1
		{
			p3->next = p2;  //p2接到L3上
			p3 = p2;
			p2 = p2->next;
		}

	}

	p3->next = p1 ? p1 : p2;  //把还有项的多项式 剩下的所有项都接到L3

	return L3;

}

Polynomial Minus(Polynomial L1, Polynomial L2)
{//L2所有系数取相反数 再加到L1
	PNode* p = L2->next;
	while (p)
	{
		p->a *= -1;
		p = p->next;
	}
	return Add(L1, L2);
}

Polynomial Mul(Polynomial L1, Polynomial L2)
{
	PNode* p1 = L1->next;
	PNode* p2 = L2->next;

	Polynomial L3;  //存储相乘结果
	CreatePolynomial(L3, 0);

	Polynomial temp;  //记录中间结果
	CreatePolynomial(temp, 0);

	//每项相乘 逐项加到L3上
	while (p1)
	{
		while (p2)
		{
			//两项相乘
			PNode* t = new PNode;
			t->next = NULL;
			t->a = p1->a * p2->a;
			t->x = p1->x + p2->x;

			//拼成一个链表 加到L3上
			temp->next = t;
			L3 = Add(L3, temp);
			p2 = p2->next;
		}
		p2 = L2->next;
		p1 = p1->next;
	}
	return L3;
}

Polynomial Diff(Polynomial L)
{//求导
	PNode* p = L->next;
	PNode* r = NULL;
	while (p)
	{
		p->a *= p->x;
		p->x--;
		if (p->x < 0) 
		{
			r = p;
			p = p->next;
			delete r;
		}
		else 
		{
			p = p->next;
		}
	}
	return L;
}

int main()
{
	int T; cin >> T;  //数据组数
	while (T--)
	{
		int a, b;  //两个多项式的项数
		cin >> a >> b;

		Polynomial L1, L2;
		CreatePolynomial(L1, a);
		CreatePolynomial(L2, b);

		char op;
		cin >> op;
		Polynomial result=nullptr,result2=nullptr;
		switch (op)
		{
		case '+':
			result=Add(L1, L2);
			OutputPolynomial(result);
			break;
		case '-':
			result = Minus(L1, L2);
			OutputPolynomial(result);
			break;
		case '*':
			result = Mul(L1, L2);
			OutputPolynomial(result);
			break;
		case '\'':
			result = Diff(L1);
			result2 = Diff(L2);
			OutputPolynomial(result);
			OutputPolynomial(result2);
			break;
		default:
			break;
		}
		/*if (op == '+')
			OutputPolynomial(Add(L1, L2));
		if (op == '-')
			Minus(L1, L2);
		if (op == '*')
			Mul(L1, L2);
		if (op == '\'') 
		{
			Diff(L1);
			Diff(L2);
		}*/
	}
	system("pause");
	return 0;
}
