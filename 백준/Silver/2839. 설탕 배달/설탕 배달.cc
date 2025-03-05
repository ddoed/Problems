#include <iostream>

using namespace std;

int dp[5000] = { 0 };

int DP(int n)
{
	if (dp[n] == 0)
	{
		dp[n] = min(DP(n - 5) + 1, DP(n - 3) + 1);
	}
	else if (dp[n] < 0)
	{
		return 4000;
	}
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;
	dp[6] = 2;

	int result = DP(n);

	if (result >= 4000) cout << -1;
	else cout << result;

	return 0;
}