#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int h, w;
int grid[21][21];
int visited[21][21];

int maxXor = 0;

void DFS(int i, int j) {
	if (j > w) {
		j = 1;i++;
	}
	if (i > h) {
		int xors = 0;
		for (int i = 1;i <= h;i++) {
			for (int j = 1;j <= w;j++) {
				if (visited[i][j] != 1) xors ^= grid[i][j];
			}
		}
		maxXor = max(maxXor, xors);
		return;
	}
	if (visited[i][j]) {
		DFS(i, j + 1);
		return;
	}

	visited[i][j] = 2;
	DFS(i, j + 1);
	visited[i][j] = 0;

	if (j + 1 <= w && visited[i][j + 1] != 1) {
		visited[i][j] = 1;
		visited[i][j + 1] = 1;
		DFS(i, j + 2);
		visited[i][j] = 0;
		visited[i][j + 1] = 0;
	}

	if (i + 1 <= h && visited[i + 1][j] != 1) {
		visited[i][j] = 1;
		visited[i + 1][j] = 1;
		DFS(i, j + 1);
		visited[i][j] = 0;
		visited[i + 1][j] = 0;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;
	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			cin >> grid[i][j];
		}
	}
	DFS(1, 1);
	cout << maxXor;
}
