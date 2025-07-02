#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

signed main() {
	int n;
	cin >> n;
	vector<string> v;
	unordered_set<string> us;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		if (us.find(s) == us.end()) {
			v.push_back(s);
			us.emplace(s);
		}
	}
	vector<int> cnt(us.size(), 0);
	for (int i = 0;i < us.size();i++) {
		string curStr = v[i];
		for (int j = 0;j < us.size();j++) {
			if (i == j) continue;
			bool flag = true;
			for (int k = 0;k < v[i].length(); k++) {
				if (v[i][k] != v[j][k]) {
					flag = false;
					break;
				}
			}
			if (flag) cnt[i]++;
		}
	}
	int ans = 0;
	for (auto c : cnt) if (c == 0) ans++;
	cout << ans;
}