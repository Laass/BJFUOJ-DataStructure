#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxSize = 100;

void countSort(int *&a, int length)
{
	int lessCount;
	int *b=new int[maxSize];
	memset(b, 0, maxSize * sizeof(int));
	for (int i = 0, lessCount = 0; i < length-1; i++,lessCount=0)
	{
		for (int j = 0; j < length; j++)
			if (a[j] < a[i])
				lessCount++;
		b[lessCount] = a[i];
	}
	int t;
	for (t = 0; a[t] < a[length - 1]; t++)
		;
	b[t] = a[length - 1];
	swap(a, b);
	delete b;
}

int main()
{
	int length;
	int *arr=new int[maxSize];

	while (cin >> length && length != 0)
	{
		memset(arr, 0, maxSize * sizeof(int));
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		countSort(arr, length);
		for (int i = 0; i < length-1; i++)
			cout << arr[i]<<" ";
		cout << arr[length - 1] << endl;
	}
	system("pause");
	return 0;
}