#include <iostream>

using namespace std;

int dp[1001] = { 0 };

int main()
{
	dp[1] = 1;
	dp[2] = 2 + 1; // 3
	dp[3] = 2*2*1 +1; // 5

	int n;
	cin >> n;

	for (int i = 3;i <= n;i++)
	{
		dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
	}
	cout << dp[n];

	return 0;
}