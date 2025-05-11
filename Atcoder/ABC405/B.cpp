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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	unordered_set<int> s;
	vector<int> cnt;

	for (int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		s.insert(x);
		cnt.push_back(s.size());
	}

	int ans = 0;
	for (int i = n - 1;i >= 0;i--)
	{
		if (cnt[i] != m)
		{
			cout << ans;
			return 0;
		}
		ans++;
	}
	cout << ans;

	return 0;
}