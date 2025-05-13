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

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int dp[10001] = { 0 };
vector<tiii> fish;
int n, c;

bool cmp(tiii t1, tiii t2)
{
	if (get<0>(t1) == get<0>(t2))
	{
		return get<2>(t1) - get<1>(t1) * c > get<2>(t2) - get<1>(t2) * c;
	}
	return get<0>(t1) > get<0>(t2);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0;i < n;i++)
	{
		int x, s, w;
		cin >> x >> s >> w;
		int m = w - x * c;
		fish.push_back(make_tuple(s, x, w));
	}
	sort(fish.begin(), fish.end(), cmp);

	for (int i = 1;i <= n * 100;i++)
	{
		int total = i;
		int sum = 0;
		for (int j = 0;j < fish.size();j++)
		{
			if (total < 0) break;
			if (get<1>(fish[j]) <= total)
			{
				total -= get<1>(fish[j]);
				sum += get<2>(fish[j]) - get<1>(fish[j]) * c;
			}
		}
		dp[i] = max(sum, dp[i - 1]);
	}
	cout << dp[n * 100];

	return 0;
}