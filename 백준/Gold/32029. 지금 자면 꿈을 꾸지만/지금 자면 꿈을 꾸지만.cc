#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { 0,-1, 0,1 };
int dy[4] = { 1, 0, -1, 0 };

int t[100];

signed main() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0;i < n;i++) {
		cin >> t[i];
	}
	sort(t, t + n);

	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int x = 0;x <= a - 1;x++) {
			int sleep = b * x;
			int work = a - x;
			int cnt = 0;
			int time = 0;
			for (int k = 0;k < n;k++) {
				if (i == k) time += sleep;
				if (k >= i) {
					if (time + work <= t[k]) {
						cnt++;
						time += work;
					}
				}
				else {
					if (time + a <= t[k]) {
						cnt++;
						time += a;
					}
				}
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans;
}