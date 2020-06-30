#include<iostream>
#include<cstring>
#include<cstdlib>
#pragma warning(disable:4996)
using namespace std;

int recursiveBiSearch(int arr[], int low, int high,int target)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == target)
			return mid;
		else if (target < arr[mid])
		{
			high = mid - 1;
			return recursiveBiSearch(arr, low, high, target);
		}
		else
		{
			low = mid + 1;
			return recursiveBiSearch(arr, low, high, target);
		}
	}
	return -1;
}

int main()
{
	int length, data,target;
	int arr[100];
	while (cin>>length&&length!=0)
	{
		memset(arr, 0, 100 * sizeof(int));
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		cin >> target;
		int result = recursiveBiSearch(arr, 0, length - 1, target);
		if (result != -1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}