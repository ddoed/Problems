#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> dp(41, { -1,-1 });

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	dp[0] = { 1,0 };
	dp[1] = { 0,1 };
	dp[2] = { 1,1 };
	dp[3] = { 1,2 };

	int t, n, idx=3;
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> n;
		for (int i = idx+1;i <= n;i++)
		{
			dp[i].first = dp[i - 1].first + dp[i - 2].first;
			dp[i].second = dp[i - 1].second + dp[i - 2].second;
		}
		cout << dp[n].first << ' ' << dp[n].second << '\n';
		idx = max(n, idx);
	}

	return 0;
}