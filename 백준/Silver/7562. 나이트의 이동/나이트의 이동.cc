#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m, x, y, targetX, targetY;
int seen[301][301] = { 0 };


pair<int, int> delta[8] = {{-1,2}, {-2,1}, {1,2}, {2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	seen[x][y] = 1;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = curX + delta[i].first;
			int ny = curY + delta[i].second;

			if (nx >= 0 && nx < m && ny >= 0 && ny < m && seen[nx][ny] == 0)
			{
				q.push({ nx,ny });
				seen[nx][ny] = seen[curX][curY] + 1;
			}
		}

	}
}

int main()
{
	int t;
	cin >> t;
	for (int Case = 0; Case < t; Case++)
	{
		
		cin >> m >> x >> y >> targetX >> targetY;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				seen[i][j] = 0;
			}
		}

		BFS(x, y);

		cout << seen[targetX][targetY] - 1 << '\n';
	}
}