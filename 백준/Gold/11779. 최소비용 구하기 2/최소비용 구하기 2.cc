#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>

priority_queue<pii, vector<pii>, greater<pii>> pq;
int d[1001];
int pre[1001];
vector<pair<int,int>> adj[1001];

signed main()
{
	int v, e;
	cin >> v >> e;

	fill(d + 1, d + v + 2, INF);

	for (int i = 0;i < e;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	int st, en;
	cin >> st >> en;
	d[st] = 0;
	pq.push({ 0, st });

	while (!pq.empty())
	{
		pii top = pq.top();
		pq.pop();
		if (d[top.second] != top.first) continue;

		for (auto x : adj[top.second])
		{
			if (d[x.second] > d[top.second] + x.first)
			{
				d[x.second] = d[top.second] + x.first;
				pre[x.second] = top.second;
				pq.push({ d[x.second], x.second });
			}
		}
	}

	cout << d[en] << '\n';
	int idx = en;
	vector<int> path;
	while (idx != st)
	{
		path.push_back(idx);
		idx = pre[idx];
	}
	path.push_back(st);
	reverse(path.begin(), path.end());

	cout << path.size() << '\n';
	for (auto x : path) cout << x << ' ';

	return 0;
}