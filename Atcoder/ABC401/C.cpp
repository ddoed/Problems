#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MOD 1000000000
#define int long long

int dp[1000002];
int sum[1000002];

signed main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
	{
		if (i < k)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = (sum[i] % MOD - sum[i - k] % MOD + MOD) % MOD;
		}
		sum[i + 1] = (sum[i] % MOD + dp[i] % MOD) % MOD;
	}

	cout << dp[n];

	return 0;
}