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
#include <climits>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

char map[1000][1000];
char result[1000][1000];
bool visited[1000][1000] = { false };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1, 0, -1 };
char ch[4] = { '^', '<', 'v', '>' };
int h, w;

bool isValid(int x, int y)
{
	return x >= 0 && y >= 0 && x < h && y < w && !visited[x][y] && map[x][y] == '.';
}

queue<pii> q;

void BFS()
{
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++)
		{
			int nxtX = curX + dx[i];
			int nxtY = curY + dy[i];
			if (isValid(nxtX, nxtY))
			{
				result[nxtX][nxtY] = ch[i];
				visited[nxtX][nxtY] = true;
				q.push({ nxtX , nxtY });
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;
	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'E') q.push({ i, j });
			result[i][j] = map[i][j];
		}
	}
	BFS();

	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			cout << result[i][j];
		}
		cout << '\n';
	}

	return 0;
}