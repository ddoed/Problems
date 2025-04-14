#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<long long, long long>
#define INF 0x3f3f3f3f

int d[201][201];

signed main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++)
	{
		fill(d[i] + 1, d[i] + 1 + n, INF);
	}

	for (int i = 0;i < m;i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		d[a][b] = min(d[a][b], t);
	}
	for (int i = 1; i <= n;i++) d[i][i] = 0;

	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int k;
	cin >> k;
	vector<int> city;
	for (int i = 0;i < k;i++)
	{
		int x;
		cin >> x;
		city.push_back(x);
	}
	
	vector<int> result;
	int pmax = INF;
	for (int i = 1;i <= n;i++)
	{
		int maxTime = 0;
		bool flag = true;
		for (int j = 0;j < city.size();j++)
		{
			int num = city[j];
			if (d[num][i] == INF || d[i][num] == INF)
			{
				flag = false;
				break;
			}
			maxTime = max(d[num][i] + d[i][num], maxTime);
		}
		if (flag)
		{
			if (maxTime < pmax)
			{
				result.clear();
				result.push_back(i);
				pmax = maxTime;
			}
			else if (maxTime == pmax) result.push_back(i);
		}
	}

	for (int i = 0;i < result.size();i++)
	{
		cout << result[i] << ' ';
	}
	
	return 0;
}