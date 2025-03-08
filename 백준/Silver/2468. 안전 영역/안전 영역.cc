#include <iostream>

using namespace std;

int n;
int maxCnt = 1;
int cnt = 0;
int ground[100][100] = { 0 };
int height = 0;

void DFS(int i, int j, bool seen[100][100])
{
	seen[i][j] = true;
	if (i > 0 && !seen[i - 1][j] && ground[i - 1][j] > height)
	{
		DFS(i - 1, j, seen);
	}
	if (i < n-1 && !seen[i + 1][j] && ground[i + 1][j] > height)
	{
		DFS(i + 1, j, seen);
	}
	if (j > 0 && !seen[i][j-1] && ground[i][j - 1] > height)
	{
		DFS(i, j-1, seen);
	}
	if (j < n-1 && !seen[i][j + 1] && ground[i][j + 1] > height)
	{
		DFS(i, j+1, seen);
	}
}

int main()
{
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> ground[i][j];
			height = max(height, ground[i][j]);
		}
	}
	height--;

	while (height >= 0)
	{
		bool seen[100][100] = { false };
		cnt = 0;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (!seen[i][j] && ground[i][j] > height)
				{
					DFS(i, j, seen);
					cnt++;
				}
			}
		}
		maxCnt = max(maxCnt, cnt);
		height--;
	}

	cout << maxCnt;

	return 0;
}