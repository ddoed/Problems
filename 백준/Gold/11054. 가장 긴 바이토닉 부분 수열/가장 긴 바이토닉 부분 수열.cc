#include <iostream>

using namespace std;

int main()
{
	int n;
	int a[1001] = { 0 };
	int dp1[1001] = { 0 };
	int dp2[1001] = { 0 };
	cin >> n;

	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j<i ;j++)
		{
			if (a[j] < a[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
		}
		for (int j = n ;n-i+1 < j;j--)
		{
			if (a[j] < a[n-i+1]) dp2[n-i+1] = max(dp2[n-i+1], dp2[j] + 1);
		}
	}
	
	int m = 0;
	for (int i = 1;i <= n;i++)
	{
		m = max(dp1[i] + dp2[i], m);
	}
	cout << m+1;

	return 0;
}