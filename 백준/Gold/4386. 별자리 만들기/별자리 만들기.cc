#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;

vector<int> p(101, -1);
vector<pair<int, int>> pos(101);
vector<tuple<double, int, int>> edge;

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
	int n;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		double x, y;
		cin >> x >> y;
		pos[i] = { x,y };
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = i+1;j < n;j++)
		{
			double dx = abs(pos[i].first - pos[j].first);
			double dy = abs(pos[i].second - pos[j].second);
			double cost = sqrt(dx * dx + dy * dy);
			edge.push_back(make_tuple(cost, i, j));
		}
	}
	sort(edge.begin(), edge.end());

	int cnt = 0;
	double ans = 0;
	for (int i = 0;i < edge.size();i++)
	{
		int a, b;
		double cost;
		tie(cost, a, b) = edge[i];
		if (is_same_group(a, b)) continue;
		ans += cost;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << ans;

	return 0;
}