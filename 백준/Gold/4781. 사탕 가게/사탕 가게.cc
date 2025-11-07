#include "bits/stdc++.h"

using namespace std;

#define MOD 1e9+7
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

int p[5001];
int c[5001];
int dp[10001];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n;
		int m;
		double temp;
		cin >> n >> temp;
		if (n == 0) break;
		
		m = round(temp * 100);
		for (int i = 1; i <= n; i++) {
			cin >> c[i] >> temp;
			p[i] = round(temp*100);
		}
		memset(dp, 0, sizeof(dp));

		int ans = 0;
		for (int row = 1;row <= n;row++) {
			for (int limit = 1;limit <= m;limit++) {
				if (limit - p[row] >= 0) {
					dp[limit] = max(dp[limit], dp[limit - p[row]] + c[row]);
					ans = max(ans, dp[limit]);
				}
			}
		}
		cout << ans << '\n';
	}
}