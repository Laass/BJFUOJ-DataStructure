#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxSize = 100;


int qSearch(int a[], int low, int high,int target)
{
	while (low < high)
	{
		// 逼近可能的a[low]<target a[high]>target的位置
		if (a[low] > target&&a[high] < target)
		{
			high--;
			low++;
		}
		while (low <= high && a[high] > target)
			high--;
		if (a[high] == target)
			return high;
		while (low <= high && a[low] < target)
			low++;
		if (a[low] == target)
			return low;
	}
	return -1;
}

int main()
{
	int length, target;
	int arr[maxSize];
	
	while (cin >> length && length != 0)
	{
		memset(arr, 0, maxSize * sizeof(int));
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		cin >> target;
		int pos = qSearch(arr, 0, length - 1, target);
		if (pos != -1)
			cout << pos+1<<" "<<target << endl;
		else
			cout << "not find" << endl;
	}
	system("pause");
	return 0;
}