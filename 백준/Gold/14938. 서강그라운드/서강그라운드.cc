#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define INF 0x3f3f3f3f

int d[101][101];
int items[101];
int nxt[101][101];
bool visited[101];

signed main()
{
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1;i <= n;i++)
	{
		cin >> items[i];
	}

	for (int i = 1;i <= n;i++)
	{
		fill(d[i], d[i] + 1 + n, INF);
		d[i][i] = 0;
	}
	
	for (int i = 0;i < r;i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		d[a][b] = l;
		d[b][a] = l;
		nxt[a][b] = b;
		nxt[b][a] = a;
	}

	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	int ans = 0, sum;
	for (int i = 1;i <= n;i++)
	{
		sum = 0;
		fill(visited + 1, visited + 1 + n, 0);

		for (int j = 1;j <= n;j++)
		{
			if (d[i][j] > m) continue;
			int cur = i;
			while (cur != j)
			{
				visited[cur] = 1;
				cur = nxt[cur][j];
			}
			visited[j] = 1;
		}
		for (int j = 1;j <= n;j++)
		{
			if (visited[j]) sum += items[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;

	return 0;
}