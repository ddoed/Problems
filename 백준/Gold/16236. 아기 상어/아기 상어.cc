#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

int water[20][20];
int n;

bool isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

bool findShortest(int& curX, int& curY, int& size, int& time, int& eatCount) {
	queue<tiii> q;
	vector<pii> candidates;
	int minDist = -1;
	bool visited[20][20] = { false };
	bool flag = false;
	visited[curX][curY] = true;
	q.push({ curX, curY, 0 });
	while (!q.empty()) {
		auto [x, y, t] = q.front();
		q.pop();
		if (minDist != -1 && t > minDist) break;

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isValid(nx, ny) || visited[nx][ny] || water[nx][ny] > size) continue;

			visited[nx][ny] = true;

			if (water[nx][ny] < size && water[nx][ny] > 0) {
				if (minDist == -1) minDist = t + 1;
				if (t + 1 == minDist) candidates.push_back({ nx, ny });
			}
			q.push({ nx, ny, t + 1 });
		}
	}
	if (candidates.empty()) return false;

	sort(candidates.begin(), candidates.end());
	pii target = candidates[0];
	time += minDist;
	curX = target.first;
	curY = target.second;
	water[curX][curY] = 0;

	eatCount++;
	if (eatCount == size) { size++; eatCount = 0; }
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int curX, curY;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int num;
			cin >> num;
			if (num == 9) curX = i, curY = j;
			else water[i][j] = num;
		}
	}

	int babySize = 2;
	int time = 0;
	int eatCount = 0;
	while (findShortest(curX, curY, babySize, time, eatCount)) {
		//cout << time << endl;
	}
	cout << time;
}