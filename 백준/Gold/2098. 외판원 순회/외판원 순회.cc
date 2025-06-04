#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int w[16][16];
int dp[(1 << 16)][16];

signed main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	int ans = INF;
	for (int st = 0; st < n; st++) {
		for (int i = 0; i < (1 << n); i++) fill(dp[i], dp[i] + n, INF);
		dp[1 << st][st] = 0;

		for (int visited = 0; visited < (1 << n); visited++) {
			for (int cur = 0; cur < n; cur++) {
				if (!(visited & (1 << cur))) continue;
				for (int nxt = 0; nxt < n; nxt++) {
					if (visited & (1 << nxt)) continue;
					if (w[cur][nxt] == 0) continue;
					int nextVisited = visited | (1 << nxt);
					dp[nextVisited][nxt] = min(dp[nextVisited][nxt], dp[visited][cur] + w[cur][nxt]);
				}
			}
		}

		for (int en = 0; en < n; en++) {
			if (en == st || w[en][st] == 0) continue;
			ans = min(ans, dp[(1 << n) - 1][en] + w[en][st]);
		}
	}

	cout << ans << "\n";
}