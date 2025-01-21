#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

long long arr[2][2] = { 1,1,1,0 };
long long ans[2][2] = { 1,0,0,1 };

void multiply(long long a[2][2], long long b[2][2])
{
	long long temp[2][2] = { 0 };
	
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			for (int k = 0;k < 2;k++)
			{
				temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			a[i][j] = temp[i][j];
		}
	}
}

int main()
{
	long long n;
	cin >> n;

	long long b = n + 1;

	while (b > 0)
	{
		if (b % 2 == 1)
		{
			multiply(ans, arr);
		}
		multiply(arr, arr);
		b /= 2;
	}

	cout << ans[1][1];

	return 0;
}