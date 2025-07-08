#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

int ch[100][100];
bool visited[100][100] = { false };
int n, m;

bool isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
queue<pii> cheese;
queue<pii> outside;

void BFS(int startX, int startY) {
	queue<pii> q;
	q.push({ startX,startY });
	ch[startX][startY] = -1;
	visited[startX][startY] = true;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nxtX = x + dx[i];
			int nxtY = y + dy[i];
			if (isValid(nxtX, nxtY) && !visited[nxtX][nxtY] && ch[nxtX][nxtY] == 0) {
				ch[nxtX][nxtY] = -1;
				visited[nxtX][nxtY] = true;
				q.push({ nxtX,nxtY });
			}
		}
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> ch[i][j];
			if (ch[i][j]) cheese.push({ i,j });
		}
	}

	BFS(0, 0);
	/*for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cout << ch[i][j] << ' ';
		}
		cout << endl;
	}*/
	int time = 0;
	while (!cheese.empty()) {
		time++;
		int qSize = cheese.size();
		while (qSize--) {
			auto [x, y] = cheese.front();
			cheese.pop();
			int cnt = 0;
			for (int i = 0;i < 4;i++) {
				int nxtX = x + dx[i];
				int nxtY = y + dy[i];
				if (isValid(nxtX, nxtY) && ch[nxtX][nxtY] == -1) cnt++;
			}
			if (cnt >= 2) outside.push({ x,y });
			else cheese.push({ x,y });
		}
		while (!outside.empty()) {
			auto [x, y] = outside.front();
			outside.pop();
			BFS(x, y);
		}
	}
	cout << time;
}