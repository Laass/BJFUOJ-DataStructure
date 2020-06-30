#include<iostream>
using namespace std;
int Ack(int x, int y)
{
	if (x == 0)
		return y + 1;
	else if (x > 0 && y == 0)
		return Ack(x - 1, 1);
	else if (x > 0 && y > 0)
		return Ack(x - 1, Ack(x, y - 1));
}
int main()
{
	int x, y;
	while(cin>>x>>y&&x!=0&&y!=0)
		cout << Ack(x, y) << endl;
	system("pause");
	return 0;
}