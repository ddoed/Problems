#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>
#include <cstring>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

int room[500][500] = { 0 };
int n, m, k;
int visited[500][500] = { 0 };
int cnt = 0;
queue<pii> q2;

void BFS(int x, int y)
{	
	if (visited[x][y]) return;
	queue<pii> q;
	cnt++;
	visited[x][y] = true;
	q.push({ x,y });
	bool flag = false;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		visited[x][y] = true;
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nxtX = x + dx[i];
			int nxtY = y + dy[i];
			if (nxtX >= 0 && nxtX < n && nxtY >= 0 && nxtY < m && !visited[nxtX][nxtY])
			{
				if (abs(room[x][y] - room[nxtX][nxtY]) > k)
				{
					q2.push({ nxtX, nxtY });
					continue;
				}
				visited[nxtX][nxtY] = true;
				q.push({ nxtX, nxtY });
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> room[i][j];
		}
	}

	BFS(0, 0);
	while (!q2.empty())
	{
		auto a = q2.front();
		q2.pop();
		BFS(a.first, a.second);
	}
	
	cout << cnt;

	return 0;
}