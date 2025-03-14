#include <iostream>

using namespace std;

char arr[100][100] = { 0 };
bool seen[100][100] = { false };
bool RGseen[100][100] = { false };
pair<int, int> delta[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int cnt = 0;
int RGcnt = 0;
int n;

void DFS(int i, int j, bool isRG)
{
	if (isRG) RGseen[i][j] = true;
	else seen[i][j] = true;

	for (int k = 0;k < 4;k++)
	{
		int dx = i + delta[k].first;
		int dy = j + delta[k].second;

		if (dx >= 0 && dy >= 0 && dx < n && dy < n)
		{
			if (isRG)
			{
				if (!RGseen[dx][dy] && (arr[i][j] == arr[dx][dy] || (arr[i][j] != 'B' && arr[dx][dy] != 'B')))
				{
					DFS(dx, dy, true);
				}
			}
			else
			{
				if (!seen[dx][dy] && arr[i][j] == arr[dx][dy])
				{
					DFS(dx, dy, false);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (!seen[i][j])
			{
				cnt++;
				DFS(i, j, false);
			}
			if (!RGseen[i][j])
			{
				RGcnt++;
				DFS(i, j, true);
			}
		}
	}

	cout << cnt << ' ' << RGcnt;
	
	return 0;
}