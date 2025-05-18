#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<int> p(1000001, -1);
int n, m;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < m;j++) {
			int idx = i*m + j;
			int nxt = idx;
			if (s[j] == 'U') nxt -= m;
			else if (s[j] == 'D') nxt += m;
			else if (s[j] == 'L') nxt -= 1;
			else if (s[j] == 'R') nxt += 1;

			if (find(idx) != find(nxt)) uni(idx, nxt);
		}
	}

	int cnt = 0;
	for (int i = 0;i < n * m;i++) {
		if (p[i] < 0) cnt++;
	}
	cout << cnt;

	return 0;
}