#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c;
bool visited[20][20] = { false };
char map[20][20];
bool visitedChar[36] = { false };

int maxDepth = 0;

void DFS(int x, int y, int depth)
{
	bool flag = false;
	for (int i = 0;i < 4;i++)
	{
		int nxtX = x + dx[i];
		int nxtY = y + dy[i];

		if (nxtX >= 0 && nxtY >= 0 && nxtX < r && nxtY < c && !visited[nxtX][nxtY] && !visitedChar[map[nxtX][nxtY] - 'A'])
		{
			flag = true;
			visited[nxtX][nxtY] = true;
			visitedChar[map[nxtX][nxtY] - 'A'] = true;
			DFS(nxtX, nxtY, depth + 1);
			visited[nxtX][nxtY] = false;
			visitedChar[map[nxtX][nxtY] - 'A'] = false;
		}
	}
	if (!flag)
	{
		maxDepth = max(maxDepth, depth);
	}
}

signed main()
{
	cin >> r >> c;

	for (int i = 0;i < r;i++)
	{
		string s;
		cin >> s;
		for (int j = 0;j < c;j++)
		{
			map[i][j] = s[j];
		}
	}

	visited[0][0] = true;
	visitedChar[map[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	cout << maxDepth;
	
	return 0;
}

