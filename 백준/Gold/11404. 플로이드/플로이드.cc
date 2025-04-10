#include <iostream>

using namespace std;

#define int long long
#define INF 0x3f3f3f3f

int d[101][101];

signed main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1;i <= n;i++)
	{
		fill(d[i], d[i] + 1 + n, INF);
	}

	for (int i = 0;i < m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(c, d[a][b]);
	}
	for (int i = 1;i <= n;i++) d[i][i] = 0;

	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (d[i][j] == INF) cout << "0 ";
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}