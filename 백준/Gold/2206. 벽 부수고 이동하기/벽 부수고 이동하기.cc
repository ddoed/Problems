#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

int wMap[1001][1001];
int n, m;
bool visited[1001][1001][2];
queue<tuple<int, int, bool, int>> q;

bool flag = false;

bool isValid(int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= m;
}

void BFS(vector<vector<vector<bool>>>& visited) {
	q.push({ 1,1,false,1 });
	visited[1][1][0] = true;

	while (!q.empty()) {
		auto [x, y, breakWall, dist] = q.front();
		q.pop();


		if (x == n && y == m) {
			cout << dist;
			return;
		}

		for (int j = 0;j < 4;j++) {
			int nxtX = x + dx[j];
			int nxtY = y + dy[j];

			if (!isValid(nxtX, nxtY)) continue;

			if (wMap[nxtX][nxtY]) {
				if (!breakWall && !visited[nxtX][nxtY][1]) {
					visited[nxtX][nxtY][1] = true;
					q.push({ nxtX, nxtY, true, dist+1 });
				}
			}
			else {
				if (!visited[nxtX][nxtY][breakWall]) {
					visited[nxtX][nxtY][breakWall] = true;
					q.push({ nxtX, nxtY, breakWall, dist + 1 });
				}
			}
		}
	}
	cout << -1;
}

signed main() {
	cin >> n >> m;
	vector<vector<vector<bool>>> visited(n + 1, vector<vector<bool>>(m + 1, vector<bool>(2)));
	for (int i = 1;i <= n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < m;j++) {
			wMap[i][j + 1] = s[j] == '1' ? 1 : 0;
		}
	}
	BFS(visited);
}