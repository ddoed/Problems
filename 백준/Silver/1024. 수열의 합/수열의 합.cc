#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

signed main() {
	int n, l;
	cin >> n >> l;
	int i=0, k=0;

	for (k = l;k <= 100;k++) {
		if ((2 * n - k * (k - 1)) % (2 * k) == 0) {
			i = (2 * n - k * (k - 1)) / (2 * k);
			if (i >= 0) break;
		}
	}

	if (k > 100) cout << -1;
	else for (int j = i;j < i + k;j++) cout << j << ' ';
}