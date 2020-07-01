#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

void findSum(int arr[], int length, int target)
{
	for (int i = 0; i < length - 1; i++)
	{
		int otherNum = target - arr[i];
		for (int j = i + 1; j < length; j++)
			if (arr[j] == otherNum)
			{
				cout << i << " " << j << endl;
				return;
			}
	}
}

int main()
{
	int arr[100], length,target;
	while (cin >> length && length != 0)
	{
		memset(arr, 0, 100 * sizeof(int));
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		cin >> target;
		findSum(arr, length,target);
	}
	system("pause");
	return 0;
}