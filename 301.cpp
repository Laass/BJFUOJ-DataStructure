#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxSize = 100;

void crrMove(int *&arr,int length,int step)
{
	// 左移step次
	for (int i = 0; i < step; i++)
	{
		// 左移一次
		int stop = 0 - 1 + length;
		for (int i = 0; i < stop; i++)
		{
			swap(arr[i], arr[(i - 1 + length) % length]);
		}
	}
}

int main()
{
	int length, step;
	int *arr=new int[maxSize];
	while (cin >> length && length != 0)
	{
		memset(arr, 0, maxSize * sizeof(int));
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		cin >> step;
		crrMove(arr,length, step);
		for (int i = 0; i < length - 1; i++)
			cout << arr[i] << " ";
		cout << arr[length - 1] << endl;
	}
	system("pause");
	return 0;
}