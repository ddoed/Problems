#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>
#include <cstring>
#include <string>
#include <numeric> // gcd

using namespace std;

#define MOD 1000000007
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

int map[8][8];
int temp[8][8];
int visited[8][8];
int n, m;
int maxArea = 0;

bool isValid(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

void BFS()
{
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			visited[i][j] = temp[i][j];
			if (visited[i][j] == 2) q.push({ i,j });
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nxtX = cur.first + dx[i];
			int nxtY = cur.second + dy[i];
			if (isValid(nxtX, nxtY) && visited[nxtX][nxtY] == 0)
			{
				q.push({ nxtX, nxtY });
				visited[nxtX][nxtY] = 2;
			}
		}
	}
}

void DFS(int cnt)
{
	if (cnt == 3)
	{
		BFS();
		int num = 0;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (visited[i][j] == 0) num++;
			}
		}
		maxArea = max(num, maxArea);
		return;
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (temp[i][j] == 0)
			{
				temp[i][j] = 1;
				DFS(cnt+1);
				temp[i][j] = 0;
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> map[i][j];
			temp[i][j] = map[i][j];
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (map[i][j] == 0)
			{
				temp[i][j] = 1;
				DFS(1);
				temp[i][j] = 0;
			}
		}
	}
	cout << maxArea;

	return 0;
}