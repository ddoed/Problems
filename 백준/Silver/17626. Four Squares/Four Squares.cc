#include <iostream>

using namespace std;

long long dp[50000] = { 0 };

int main()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;
	dp[5] = dp[4] + dp[1];
	dp[6] = dp[4] + dp[2];
	dp[7] = dp[4] + dp[3];
	dp[8] = dp[4] + dp[4];
	dp[9] = 1;

	int n;
	cin >> n;
	for (int i = 10;i <= n;i++)
	{
		dp[i] = 5;
		for (int j = 1;j * j <= i;j++)
		{
			if (j * j == i) dp[i] = 1;
			else dp[i] = min(dp[i], dp[i-j*j]+dp[j*j]);
		}
	}
	cout << dp[n];

	return 0;
}