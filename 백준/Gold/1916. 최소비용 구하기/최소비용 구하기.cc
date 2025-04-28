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

vector<pair<int, int>> adj[1001];
int d[1001];

signed main()
{
	int v, e;
	cin >> v >> e;

	fill(d + 1, d + v + 1, INF);

	for (int i = 0;i < e;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	int st, en;
	cin >> st >> en;
	d[st] = 0;
	pq.push({ 0 , st });
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second])
		{
			if (d[nxt.second] > d[cur.second] + nxt.first)
			{
				d[nxt.second] = d[cur.second] + nxt.first;
				pq.push({ d[nxt.second], nxt.second });
			}
		}
	}

	cout << d[en];
	

	return 0;
}

