#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxSize = 100;

int findMainELem(int arr[], int length)
{
	int b[maxSize];
	memset(b, 0, maxSize * sizeof(int));
	// maxVaule数组中数的最大值 为了取消遍历b时大于最大值的几趟
	int maxValue=0, maxOccur=0,maxOccurValue;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > maxValue)
			maxValue = arr[i];
		b[arr[i]]++;
	}
	for (int j = 0; j < maxValue; j++)
		if (b[j] > maxOccur)
		{
			maxOccur = b[j];  // 最多出现次数
			maxOccurValue = j;  //出现次数最多的值
		}
	if (maxOccur > length / 2)
		return maxOccurValue;
	else
		return -1;

}

int main()
{
	int length;
	int arr[maxSize];
	while (cin >> length && length != 0)
	{
		memset(arr, 0, maxSize * sizeof(int));
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		int val=findMainELem(arr, length);
		if (val != -1)
			cout << val << endl;
		else
			cout << -1 << endl;
	}
	system("pause");
	return 0;
}