#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int dist[501];
vector<pii> adj[501];

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int st, en, cost;
		cin >> st >> en >> cost;
		adj[st].push_back({ en, cost });
	}
	
	bool mflag = false;
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (auto [nxt, cost] : adj[j]) {
				if (dist[j] != INF && dist[nxt] > dist[j] + cost) {
					dist[nxt] = dist[j] + cost;
					if (i == n) mflag = true;
				}
			}
		}
	}
	if (mflag) cout << -1;
	else for (int i = 2;i <= n;i++) cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
}