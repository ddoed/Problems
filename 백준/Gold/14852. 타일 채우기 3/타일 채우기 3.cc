#include <iostream>

using namespace std;

#define MOD 1000000007

long long dp[1000001] = { 0 };

int main()
{
	long long n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;

	long long sum = dp[0];

	for (int i = 3;i <= n;i++)
	{
		dp[i] = ((dp[i - 1] * 2) % MOD + (dp[i - 2] * 3) % MOD + (sum*2) % MOD) % MOD;
		sum = (sum + dp[i - 2]) % MOD;
	}
	cout << dp[n];

	return 0;
}