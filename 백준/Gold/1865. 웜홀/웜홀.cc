#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

signed main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, w;
		cin >> n >> m >> w;
		int dist[501];
		vector<pii> adj[501];
		for (int i = 0;i < m;i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back({ e,t });
			adj[e].push_back({ s,t });
		}
		for (int i = 0;i < w;i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back({ e,-t });
		}

		bool flag = false;
		fill(dist, dist + n + 1, INF);
		dist[1] = 0;
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= n; k++) {
				for (auto [nxt, cost] : adj[k]) {
					if (dist[nxt] > dist[k] + cost) {
						dist[nxt] = dist[k] + cost;
						if (j == n) flag = true;
					}
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}