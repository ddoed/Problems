#include <iostream>

using namespace std;

int main()
{
	int n, cnt=0;
	cin >> n;

	for (int i = n;i >= 5;i--)
	{
		int num = i;
		while (num%5 == 0)
		{
			cnt++;
			num /= 5;
		}
	}
	cout << cnt;

	return 0;
}