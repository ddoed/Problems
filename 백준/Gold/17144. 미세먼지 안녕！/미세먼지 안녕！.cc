#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int dust[51][51];
int sums[51][51];
queue<pii> q;
vector<pii> air;
int r, c, t;

bool isValid(int x, int y) {
	if (x >= 1 && y >= 1 && x <= r && y <= c) return true;
	return false;
}

void BFS(int t) {
	int time = 0;
	while (time < t) {
		time++;
		int qSize = q.size();
		while (qSize--) {
			auto [x, y] = q.front();
			q.pop();
			int cnt = 0;
			for (int i = 0;i < 4;i++) {
				int nxtX = x + dx[i];
				int nxtY = y + dy[i];
				if (isValid(nxtX, nxtY) && dust[nxtX][nxtY] != -1) {
					sums[nxtX][nxtY] += dust[x][y] / 5;
					cnt++;
				}
			}
			sums[x][y] -= dust[x][y] / 5 * cnt;
		}

		for (int i = 1;i <= r;i++) {
			for (int j = 1;j <= c;j++) {
				dust[i][j] += sums[i][j];
				sums[i][j] = 0;
			}
		}

		int upX = air[0].first;
		int downX = air[1].first;

		// 위쪽 반시계 방향
		for (int i = upX - 1; i > 1; i--) dust[i][1] = dust[i - 1][1];
		for (int i = 1; i < c; i++) dust[1][i] = dust[1][i + 1];
		for (int i = 1; i < upX; i++) dust[i][c] = dust[i + 1][c];
		for (int i = c; i > 2; i--) dust[upX][i] = dust[upX][i - 1];
		dust[upX][2] = 0;

		// 아래쪽 시계 방향
		for (int i = downX + 1; i < r; i++) dust[i][1] = dust[i + 1][1];
		for (int i = 1; i < c; i++) dust[r][i] = dust[r][i + 1];
		for (int i = r; i > downX; i--) dust[i][c] = dust[i - 1][c];
		for (int i = c; i > 2; i--) dust[downX][i] = dust[downX][i - 1];
		dust[downX][2] = 0;
		
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (dust[i][j] > 0) q.push({ i, j });
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> r >> c >> t;

	for (int i = 1;i <= r;i++) {
		for (int j = 1;j <= c;j++) {
			cin >> dust[i][j];
			if (dust[i][j] > 0) q.push({ i,j });
			if (dust[i][j] < 0) air.push_back({ i,j });
		}
	}
	BFS(t);
	int ans = 0;
	for (int i = 1;i <= r;i++) {
		for (int j = 1;j <= c;j++) {
			if (dust[i][j] > 0) ans += dust[i][j];
		}
	}
	cout << ans;
}
