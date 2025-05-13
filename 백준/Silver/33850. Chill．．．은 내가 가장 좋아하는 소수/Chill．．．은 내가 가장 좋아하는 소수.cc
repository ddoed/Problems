#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>
#include <cstring>
#include <string>
#include <climits>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int dp[200001];

int n, a, b;

int isPrime(int n)
{
	for (int i = 2;i * i <= n;i++)
	{
		if (n % i == 0) return b;
	}
	return a;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> a >> b;

	vector<vector<int>> v(2, vector<int>(n, 0));

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> v[i][j];
		}
	}

	dp[1] = isPrime(v[0][0] + v[1][0]);
	for (int i = 2;i <= n;i++)
	{
		dp[i] = max(isPrime(v[0][i - 1] + v[1][i - 1]) + dp[i - 1], isPrime(v[0][i - 2] + v[0][i - 1]) + isPrime(v[1][i - 2] + v[1][i - 1]) + dp[i - 2]);
	}
	cout << dp[n];

	return 0;
}