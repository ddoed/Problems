#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,m=0;
	int dp[101] = { 0 };

	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0;i < n;i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < i;j++)
		{
			if (v[i].second > v[j].second) dp[i] = max(dp[i], dp[j] + 1);
			m = max(dp[i], m);
		}
	}
	cout << n - (m + 1);


	return 0;
}