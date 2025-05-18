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

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];

	int result = 1;
	for (auto a : v) {
		if (result > LLONG_MAX / a) {
			result = 1;
			continue;
		}
		result *= a;
		if (to_string(result).length() > k) result = 1;
	}
	cout << result;
}
