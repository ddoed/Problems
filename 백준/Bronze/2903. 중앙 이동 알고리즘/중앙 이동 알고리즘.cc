#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int num1 = 2;
	int num2;
	for (int i = 0;i < n-1;i++)
	{
		num2 = 2*num1 - 1;
		num1 = num2;
	}
	cout << (num1 * 2 - 1)*(num1 * 2 - 1);
}