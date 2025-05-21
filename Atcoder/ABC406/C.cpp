= #include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	vector<pair<char, int>> v;
	for (int i = 0; i < n - 1;i++) {
		if (p[i] < p[i + 1]) {
			if (v.empty() or v.back().first == '>') v.push_back({ '<', 1 });
			else v.back().second++;
		}
		else {
			if (v.empty() or v.back().first == '<') v.push_back({ '>', 1 });
			else v.back().second++;
		}
	}
	int sz = v.size();
	int ans = 0;
	for (int i = 1;i < sz - 1;i++)
		if (v[i].first == '>') ans += v[i - 1].second * v[i + 1].second;
	cout << ans;
}
