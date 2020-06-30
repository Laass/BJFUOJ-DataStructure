#include<iostream>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

void posNegSort(int *arr,int length)
{
	int *pos = (int*)malloc(length * sizeof(int));
	memset(pos, 0, length * sizeof(int));
	int *neg = (int*)malloc(length * sizeof(int));
	memset(pos, 0, length * sizeof(int));
	int posLength=0, negLength=0,posInd=0,negInd=0;
	for(int i=0;i<length;i++)
		if (arr[i] > 0)
		{
			pos[posInd++] = arr[i];
			posLength++;
		}
		else if(arr[i]<0)
		{
			neg[negInd++] = arr[i];
			negLength++;
		}
	for (posInd = 0; posInd < posLength; posInd++)
		arr[posInd] = pos[posInd];
	for (negInd = 0; negInd < negLength; negInd++, posInd++)
		arr[posInd] = neg[negInd];
	free(pos);
	free(neg);
}
int main()
{
	int length;
	while (cin >> length && length != 0)
	{
		int *arr = (int*)malloc(length * sizeof(int));
		memset(arr, 0, length * sizeof(int));
		for (int i = 0; i < length; i++)
			cin >> arr[i];
		posNegSort(arr, length);
		for (int i = 0; i < length - 1; i++)
			cout << arr[i] << " ";
		cout << arr[length - 1] << endl;
		free(arr);
	}
	system("pause");
	return 0;
}