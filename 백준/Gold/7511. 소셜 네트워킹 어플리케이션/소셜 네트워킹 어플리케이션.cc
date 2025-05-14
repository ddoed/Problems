#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>



int find(int x, vector<int>& p)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x], p);
}

void uni(int u, int v, vector<int>& p)
{
	u = find(u, p);
	v = find(v, p);
	if (u == v) return;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int i = 1;
	while (i <= t)
	{
		
		vector<int> p(1000000, -1);
		int n, k;
		cin >> n >> k;
		for (int i = 0;i < k;i++)
		{
			int a, b;
			cin >> a >> b;
			uni(a, b, p);
		}

		int m;
		cin >> m;
		vector<int> result;
		for (int i = 0;i < m;i++)
		{
			int u, v;
			cin >> u >> v;
			if (find(u, p) == find(v, p)) result.push_back(1);
			else result.push_back(0);
		}
		cout << "Scenario " << i << ":\n";
		for (auto r : result) cout << r << '\n';
		cout << '\n';
		i++;
	}

	return 0;
}