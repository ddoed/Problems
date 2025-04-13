#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

#define tiii tuple<int,int,int>

vector<int> p(10001, -1);
tiii edge[100001];

int find(int x)
{
	if (p[x] < 0) return x;
	else return p[x] = find(p[x]);
}

bool is_same_group(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return true;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;
	return false;
}

int main()
{
	int v, e;
	cin >> v >> e;

	for (int i = 0;i < e;i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = make_tuple(cost, a, b);
	}
	sort(edge, edge + e);

	int cnt = 0;
	int ans = 0;
	for (int i = 0;i < e;i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		if (is_same_group(a, b)) continue;
		ans += cost;
		cnt++;
		if (cnt == v - 1) break;
	}

	cout << ans;

	return 0;
}