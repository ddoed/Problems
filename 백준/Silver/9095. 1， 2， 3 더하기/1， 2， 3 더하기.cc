#include <iostream>
#include <vector>

using namespace std;

int dp[12] = { 0 };

int main()
{
	int t, n;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	dp[5] = 13; 

	int idx = 5;
	for (int i = 0;i < t;i++)
	{
		cin >> n;
		for (int j = idx + 1;j <= n;j++)
		{
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[n] << '\n';
		idx = max(n, idx);
	}
	

	return 0;
}