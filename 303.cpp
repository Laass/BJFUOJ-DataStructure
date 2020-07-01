#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxSize = 100;

int partition(int arr[], int low, int high)
{
	int pivotKey = arr[low];
	while (low < high)
	{
		while (low < high&&arr[high] >= pivotKey)
			high--;
		arr[low] = arr[high];
		while (low < high&&arr[low] <= pivotKey)
			low++;
		arr[high] = arr[low];
	}
	arr[low] = pivotKey;
	return low;
}

int divide(int arr[], int length)
{
	int low = 0, high = length - 1;
	int pivotIndex = -1;
	while (low < high)
	{
		pivotIndex = partition(arr, low, high);
		if (pivotIndex == length / 2)
			return pivotIndex;
		else if (pivotIndex < length / 2)
			low = pivotIndex + 1;
		else
			high = pivotIndex - 1;
	}
	return low;
}

int main()
{
	int length, arr[maxSize];
	while (cin >> length && length != 0)
	{
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		int pivotLoc = divide(arr, length);

		for (int i = 0; i < pivotLoc-1; ++i)
			cout << arr[i] << " ";
		cout << arr[pivotLoc - 1] << endl;
		for (int i = pivotLoc; i < length-1; ++i)
			cout << arr[i] << " ";
		cout << arr[length-1]<<endl;

	}
	system("pause");
	return 0;
}