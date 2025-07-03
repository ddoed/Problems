#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

vector<int> delay(1001, 0);


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		vector<int> adj[1001];
		int deg[1001] = { 0 };
		int dp[1001] = { 0 };
		int n, k, w;
		cin >> n >> k;
		for (int i = 1;i <= n;i++) {
			cin >> delay[i];
			dp[i] = delay[i];
		}
		for (int i = 0;i < k;i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			deg[y]++;
		}
		cin >> w;

		queue<int> nodes;
		for (int i = 1;i <= n;i++) if (deg[i] == 0) nodes.push(i);

		while (!nodes.empty()) {
			int cur = nodes.front(); nodes.pop();
			
			for (auto nxt : adj[cur]) {
				dp[nxt] = max(dp[nxt], dp[cur] + delay[nxt]);
				deg[nxt]--;
				if (deg[nxt] == 0) nodes.push(nxt);
			}
		}
		cout << dp[w] << '\n';
	}
}