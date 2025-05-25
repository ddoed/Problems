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

	int cnt = 0;

	int x, y;
	cin >> x >> y;
	for (int i = 1;i <= 6;i++) {
		for (int j = 1;j <= 6;j++) {
			if (i + j >= x || abs(i - j) >= y) cnt++;
		}
	}
	cout.precision(10);
	cout << (double)cnt / 36;
}
