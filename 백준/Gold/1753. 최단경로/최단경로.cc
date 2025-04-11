#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>

priority_queue<pii, vector<pii>, greater<pii>> pq;
int d[20001];
vector<pair<int,int>> adj[20001];

signed main()
{
	int v, e, k;
	cin >> v >> e >> k;

	fill(d + 1, d + v + 2, INF);
	d[k] = 0;
	pq.push({ 0, k });

	for (int i = 0;i < e;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

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
				pq.push({ d[x.second], x.second });
			}
		}
	}

	for (int i = 1;i <= v;i++)
	{
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}

	return 0;
}