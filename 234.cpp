#include<iostream>
#include<cstdlib>
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

private:
	static const int initCapacity = 2;
};

int main()
{
	int length, e,target;
	cin >> length;
	while (length != 0)
	{
		List l;
		while (length--)
		{
			cin >> e;
			l.insert(e);
		}
		cin >> target;
		l.delAll(target);
		l.traverse();
		cin >> length;
	}
	system("pause");
	return 0;
}