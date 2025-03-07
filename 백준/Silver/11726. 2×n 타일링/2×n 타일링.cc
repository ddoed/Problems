#include <iostream>

using namespace std;

int dp[1001] = { 0 };

int main()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3; // 1+2
	dp[4] = 5; // 1+3+1
	dp[5] = 8;
	dp[6] = 13;

	int n;
	cin >> n;

	for (int i = 7;i <= n;i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n];

	return 0;
}