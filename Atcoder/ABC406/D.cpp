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

	int h, w, n;
	cin >> h >> w >> n;
	vector a(h + 1, vector<int>());
	vector b(w + 1, vector<int>());
	// ux[x] : x행이 이미 사용됐는지
	// uy[y] : y열이 이미 사용됐는지
	vector<bool> ux(h + 1), uy(w + 1);
	// i번째 쓰레기가 사용됐는지
	vector<bool> used(n);

	for (int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		// 쓰레기 인덱스 저장
		a[x].push_back(i);
		b[y].push_back(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			if (ux[x]) cout << 0 << '\n';
			else {
				int ans = 0;
				for (int e : a[x]) {
					if (!used[e]) {
						used[e] = true;
						ans++;
					}
				}
				ux[x] = true;
				cout << ans << '\n';
			}
		}
		else {
			int y;
			cin >> y;
			if (uy[y]) cout << 0 << '\n';
			else {
				int ans = 0;
				for (int e : b[y]) {
					if (!used[e]) {
						used[e] = true;
						ans++;
					}
				}
				uy[y] = true;
				cout << ans << '\n';
			}
		}
	}
}
