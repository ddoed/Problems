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

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int map[1000][1000];
int result[1000][1000];
int sums[1000][1000];
int idx[1000][1000];
bool visited[1000][1000] = { false };
int dx[4] = { 1,0,-1,0 };
int dy[4] = {0, 1, 0, -1};
int n, m;
int cnt = 0;
vector<pii> pos;

void DFS(int x, int y)
{
	visited[x][y] = true;
	cnt++;
	for (int i = 0;i < 4;i++)
	{
		int nxtX = x + dx[i];
		int nxtY = y + dy[i];
		if (nxtX >= 0 && nxtY >= 0 && nxtX < n && nxtY < m && !visited[nxtX][nxtY] && map[nxtX][nxtY] != 1)
		{
			DFS(nxtX, nxtY);
			pos.push_back({ nxtX, nxtY });
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
		string s;
		cin >> s;
		for (int j = 0;j < m;j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	int num = 1;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (map[i][j] != 0 || sums[i][j] != 0) continue;
			memset(visited, 0, sizeof(visited));
			cnt = 0;
			pos.clear();
			DFS(i, j);
			sums[i][j] = cnt;
			idx[i][j] = num;
			for (auto p : pos)
			{
				sums[p.first][p.second] = cnt;
				idx[p.first][p.second] = num;
			}
			num++;
		}
	}
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (map[i][j] == 0) continue;
			int sum = 0;
			unordered_set<int> idxVisited;
			for (int k = 0;k < 4;k++)
			{
				int nxtX = i + dx[k];
				int nxtY = j + dy[k];
				if (nxtX < 0 || nxtY < 0 || nxtX >= n || nxtY >= m) continue;
				if (idxVisited.find(idx[nxtX][nxtY]) == idxVisited.end())
				{
					idxVisited.insert(idx[nxtX][nxtY]);
					sum += sums[nxtX][nxtY];
				}
			}
			result[i][j] = sum+1;
		}
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << result[i][j] % 10;
		}
		cout << endl;
	}

	return 0;
}