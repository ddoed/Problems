#include <iostream>
#include <queue>

using namespace std;

int ground[1000][1000] = { 0 };
long long result[1000][1000] = { 0 };
bool seen[1000][1000] = { false };

queue<pair<int,int>> q;
pair<int, int> delta[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int n, m, x, y;

void BFS(int x, int y)
{
	q.push({ x,y });
	seen[x][y] = true;
	result[x][y] = 0;

	while (!q.empty()) 
	{
		pair<int, int> num = q.front();
		q.pop();

		for (int i = 0;i < 4;i++)
		{
			int dx = num.first + delta[i].first;
			int dy = num.second + delta[i].second;

			if (dx >= 0 && dy >= 0 && dx < n && dy < m && ground[dx][dy] != 0 && !seen[dx][dy])
			{
				seen[dx][dy] = true;
				result[dx][dy] = result[num.first][num.second] + 1;
				q.push({ dx,dy });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> ground[i][j];

			if (ground[i][j] == 2)
			{
				x = i;
				y = j;
			}
		}
	}

	BFS(x,y);

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (!seen[i][j] && ground[i][j] == 1) cout << -1 << ' ';
			else cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	
	return 0;
}