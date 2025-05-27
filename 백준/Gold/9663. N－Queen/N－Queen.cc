#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

bool visited[16][16];
int n, cnt = 0;

bool isSafe(int x, int y) {
	for (int i = 0;i < x;i++) {
		if (visited[i][y]) return false;
	}
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (visited[i][j]) return false;
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
		if (visited[i][j]) return false;
	}
	return true;
}

void DFS(int i) {
	if (i == n) {
		cnt++;
		return;
	}
	for (int j = 0;j < n;j++) {
		if (!isSafe(i, j)) continue;
		visited[i][j] = true;
		DFS(i + 1);
		visited[i][j] = false;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	DFS(0);
	cout << cnt;
}
