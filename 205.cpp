#include<cstdio>
#include<cstdlib>
#pragma warning(disable:4996)

#define MAX 1000
typedef struct 
{
	double no;
	char name[MAX];
	double price;

}Book;

int createList(Book b[]);
void traverse(Book b[], int len);
void sortList(Book b[], int len);

int main()
{
	Book book[MAX];

	int len;
	len = createList(book);
	sortList(book, len);
	traverse(book, len);

	system("pause");
	return 0;
}

int createList(Book b[])
{
	int i = 0;
	while (1)
	{
		scanf("%lf", &b[i].no);
		scanf("%s", &b[i].name);
		scanf("%lf", &b[i].price);

		if (b[i].no == 0 && b[i].name[0] == '0'&&b[i].price == 0)
			break;

		i++;
	}
	return i;
}

void traverse(Book b[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%.0lf ", b[i].no);
		printf("%s ", b[i].name);
		printf("%.2f", b[i].price);
		printf("\n");
	}

}

void sortList(Book b[], int len)
{//¼òµ¥Ñ¡ÔñÅÅÐò
	int i, j;
	Book t;

	for (i = 0; i < len - 1; i++)
	{
		int max_index = i;

		for (j = i + 1; j < len; j++)
		{
			if (b[j].price >= b[max_index].price)
				max_index = j;
		}
		if (i != max_index)
		{
			t = b[i];
			b[i] = b[max_index];
			b[max_index] = t;
		}
	}
}