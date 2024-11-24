#include <iostream>
#include <algorithm>

using namespace std;

int m, n;
int ground[51][51] = { 0 };
bool seen[51][51] = { false };
int cnt;

void DFS(int y, int x)
{
	seen[y][x] = true;

	if (y - 1 >= 0 && !seen[y - 1][x] && ground[y - 1][x])
	{
		DFS(y - 1, x);
	}
	if (y + 1 < n && !seen[y + 1][x] && ground[y + 1][x])
	{
		DFS(y + 1, x);
	}
	if (x - 1 >= 0 && !seen[y][x - 1] && ground[y][x - 1])
	{
		DFS(y, x - 1);
	}
	if (x + 1 < m && !seen[y][x + 1] && ground[y][x + 1])
	{
		DFS(y, x + 1);
	}
}

int main()
{
	int t,k;
	cin >> t;

	for (int Case = 0; Case < t; Case++)
	{
		cin >> m >> n >> k;
		cnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ground[i][j] = 0;
				seen[i][j] = false;
			}
		}

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			ground[y][x] = 1;
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!seen[i][j] && ground[i][j] == 1)
				{
					cnt++;
					DFS(i, j);
				}
					
			}
		}
		cout << cnt << '\n';
	}
}