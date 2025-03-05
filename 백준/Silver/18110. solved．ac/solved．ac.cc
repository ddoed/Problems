#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int comment[300001] = { 0 };

int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			cin >> comment[i];
		}

		sort(comment + 1, comment + n+1);

		int num = round((n * 0.15));
		double sum = 0;
		for (int i = num + 1;i <= n - num;i++)
		{
			sum += comment[i];
		}

		cout << round(sum / (n - 2 * num));
	}

	return 0;
}