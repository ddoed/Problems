#include <iostream>
#include <algorithm>

using namespace std;

int board[500][500] = { 0 };
bool seen[500][500] = { false };
int n, m;
pair<int, int> delta[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int maxValue = -1;

void DFS(int i, int j, int cnt, int sum)
{
	if (cnt == 4)
	{
		maxValue = max(maxValue, sum);
		return;
	}

	for (int k = 0;k < 4;k++)
	{
		int x = i + delta[k].first;
		int y = j + delta[k].second;
		
		if (x >= 0 && y >= 0 && x <n && y<m && !seen[x][y])
		{
			seen[x][y] = true;
			DFS(x, y, cnt + 1, sum + board[x][y]);
			seen[x][y] = false;
		}
	}
}

void check(int i, int j)
{
	// ㅗ
	if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < m)
	{
		maxValue = max(maxValue, board[i][j] + board[i - 1][j] + board[i][j - 1] + board[i][j + 1]);
	}
	// ㅏ
	if (i - 1 >= 0 && i + 1 < n && j + 1 < m)
	{
		maxValue = max(maxValue, board[i - 1][j] + board[i + 1][j] + board[i][j + 1] + board[i][j]);
	}
	// ㅜ
	if (i + 1 < n && j - 1 >= 0 && j + 1 < m)
	{
		maxValue = max(maxValue, board[i][j] + board[i + 1][j] + board[i][j - 1] + board[i][j + 1]);
	}
	// ㅓ
	if (i - 1 >= 0 && i + 1 < n && j - 1 >= 0)
	{
		maxValue = max(maxValue, board[i - 1][j] + board[i + 1][j] + board[i][j - 1] + board[i][j]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			seen[i][j] = true;
			DFS(i, j, 1, board[i][j]);
			seen[i][j] = false;

			check(i,j);
		}
	}

	cout << maxValue;
	

	return 0;
}