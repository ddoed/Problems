#include <bits/stdc++.h>

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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> v(2 * n);
		for (int i = 0;i < 2 * n;i++) {
			cin >> v[i];
		}
		int ans = 0;
		priority_queue<int, vector<int>> pq;
		for (int i = 0;i < n;i++) {
			if (i == 0) {
				pq.push(v[i * 2 - 0]);
			}
			else {
				pq.push(v[i * 2 - 1]);
				pq.push(v[i * 2 - 0]);
			}
			int v = pq.top();
			pq.pop();

			ans += v;
		}
		cout << ans << '\n';
	}
}
