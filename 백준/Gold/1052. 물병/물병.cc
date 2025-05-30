#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int bitCount(int A) {
	if (A == 0) return 0;
	return (A & 1) + bitCount(A >> 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int cnt = 0;
	while (true) {
		if (bitCount(n) <= k) break;
		cnt++;
		n++;
	}
	cout << cnt;
}
