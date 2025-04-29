#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

bool visited[17][17] = { false };
int wall[17][17] = { 0 };

signed main()
{
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			int x;
			cin >> x;
			if (x == 1) wall[i][j] = 1;
		}
	}
	queue<tiii> q;

	q.push({ 1,2, -1});

	int cnt = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int curX = get<0>(cur);
		int curY = get<1>(cur);
		int dir = get<2>(cur);

		if (curX == n && curY == n)
		{
			cnt++;
			continue;
		}

		if (dir == -1)
		{
			if (curY + 1 <= n && !wall[curX][curY+1])
			{
				q.push({ curX, curY+1, dir});
				if (curX + 1 <= n && !wall[curX+1][curY+1] && !wall[curX+1][curY])
				{
					q.push({ curX + 1, curY + 1, 1 });
				}
			}
		}
		else if (dir == 0)
		{
			if (curX + 1 <= n && !wall[curX+1][curY])
			{
				q.push({ curX+1, curY, dir });
				if (curY + 1 <= n && !wall[curX + 1][curY + 1] && !wall[curX][curY+1])
				{
					q.push({ curX + 1, curY + 1, 1 });
				}
			}
		}
		else if (dir == 1)
		{
			if (curY + 1 <= n && !wall[curX][curY + 1])
			{
				q.push({ curX, curY + 1, -1 });
				if (curX + 1 <= n && !wall[curX + 1][curY + 1] && !wall[curX+1][curY])
				{
					q.push({ curX + 1, curY + 1, 1 });
				}
			}
			if (curX + 1 <= n && !wall[curX + 1][curY])
			{
				q.push({ curX + 1, curY, 0 });
			}
		}
	}

	cout << cnt;

	return 0;
}

