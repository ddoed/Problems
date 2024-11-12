#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int num = 2;
	for (int i = 0;i < n-1;i++)
	{
		num = 2*num - 1;
	}
	cout << (num * 2 - 1)*(num * 2 - 1);
}