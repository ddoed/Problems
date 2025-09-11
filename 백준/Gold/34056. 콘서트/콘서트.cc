#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { 0,-1, 0,1 };
int dy[4] = { 1, 0, -1, 0 };

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<int> d(n+1);

	for (int i = 1;i <= n;i++) {
		cin >> d[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int num, c;
		cin >> num >> c;
		if (num == 1) {
			int x;
			cin >> x;
			int noise = x;
			for (int i = c; i >= 1 && x > 0; i--) {
				int absorb = min(d[i], x);
				x -= absorb;
				d[i] += absorb;
			}
			x = noise;
			for (int i = c + 1; i <= n && x > 0;i++) {
				int absorb = min(d[i], x);
				x -= absorb;
				d[i] += absorb;
			}
		}
		else {
			cout << d[c] << '\n';
		}
	}

}