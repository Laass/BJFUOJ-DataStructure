#include<iostream>
#include<cstdlib>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;

class List
{
public:
	int *data;
	int length;
	int capacity;

	List()
	{
		this->data = new int[this->initCapacity];
		this->length = 0;
		this->capacity = this->initCapacity;
	}

	void insert(int e)
	{
		if (this->length == this->capacity)
			enlarge();
		this->data[length++] = e;
	}

	void enlarge()
	{
		int *newData = new int[capacity << 1];
		for (int i = 0; i < this->length; i++)
			newData[i] = this->data[i];
		capacity <<= 1;
		swap(newData, data);
		delete[] newData;
	}

	void delAll(int target)
	{
		if (this->length == 0)
			return;
		int i = this->length - 1;
		while (i >= 0)
		{
			while (0<=i&&this->data[i] != target)
				i--;
			removeAt(i);
			i--;
		}
	}

	void removeAt(int pos)
	{
		if (pos < 0 || this->length <= pos)
			return;
		for (int i = pos; i <this->length-1; i++)
			this->data[i] = this->data[i+1];
		this->length--;
		if (this->length < this->capacity/2)
			shrink();
	}

	void shrink()
	{
		int *newData = new int[capacity >> 1];
		for (int i = 0; i < this->length; i++)
			newData[i] = this->data[i];
		capacity >>= 1;
		swap(newData, data);
		delete[] newData;
	}

	void traverse()
	{
		for (int i = 0; i < this->length - 1; i++)
			cout << this->data[i] << " ";
		cout << this->data[length - 1] << endl;
	}

	void merge(List b)
	{
		List nl;
		int i, j;
		for (i = 0, j = 0; i < this->length&&j < b.length;)
		{
			if (this->data[i] <= b.data[j])
			{
				nl.insert(this->data[i]);
				i++;
			}
			else
			{
				nl.insert(b.data[j]);
				j++;
			}
		}
		while(i<this->length)
			nl.insert(this->data[i++]);
		while (j < b.length)
			nl.insert(b.data[j++]);
		swap(this->data, nl.data);
		swap(this->length, nl.length);
		swap(this->capacity, nl.capacity);
	}

private:
	static const int initCapacity = 20;
};

int main()
{
	int length, e,target;
	cin >> length;
	while (length != 0)
	{
		List la,lb;
		int i = length;
		while (i--)
		{
			cin >> e;
			la.insert(e);
		}
		i = length;
		while (i--)
		{
			cin >> e;
			lb.insert(e);
		}
		la.merge(lb);
		cout << la.data[static_cast<int>(ceil(la.length/2.0))-1] << endl;
		cin >> length;
	}
	system("pause");
	return 0;
}