#include <iostream>

using namespace std;

#define MOD 1000000007

long long dp[1000001][2] = {0};

int main()
{
	long long n;
	cin >> n;

	dp[0][0] = 0;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;

	for (int i = 3;i <= n;i++)
	{
		dp[i][1] = (dp[i - 3][0] + dp[i - 1][1]) % MOD;
		dp[i][0] = (2 * dp[i - 1][0] + 3 * dp[i - 2][0] + 2*dp[i][1]) % MOD;
	}
	cout << dp[n][0];

	return 0;
}