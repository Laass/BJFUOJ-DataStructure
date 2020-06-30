#include<iostream>
#include<cstring>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

const int maxSize = 100;

void posNegSort(int arr[], int length)
{
	if (length == 1)
		return;
	else if (length == 2)
	{
		if (arr[1] < 0)
			swap(arr[0], arr[1]);
	}
	else
	{
		int i, j = 0;
		while (arr[j] < 0)
			j++;
		for (i=j+1; i < length; i++)
		{
			if (arr[i] < 0)
				swap(arr[i], arr[j]);
			while (arr[j] < 0)
				j++;
		}
	}
}

int main()
{
	int arr[maxSize],length;
	while (cin >> length && length != 0)
	{
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		posNegSort(arr, length);
		for (int i = 0; i < length - 1; i++)
			cout << arr[i] << " ";
		cout << arr[length - 1] << endl;
	}
	system("pause");
	return 0;
}