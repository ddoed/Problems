#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

vector<int> p(100001, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void uni(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;
}

priority_queue<tiii> pq;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(make_tuple(c, a, b));
	}
	int p1, p2;
	cin >> p1 >> p2;

	int minW = INF;
	while (!pq.empty())
	{
		auto [c, a, b] = pq.top();
		pq.pop();

		if (find(a) != find(b))
		{
			uni(a, b);
			minW = min(minW, c);
		}
		if (find(p1) == find(p2)) break;
	}

	cout << minW;
	

	return 0;
}