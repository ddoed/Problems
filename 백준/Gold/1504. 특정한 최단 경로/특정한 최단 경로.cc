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

vector<pair<int,int>> adj[801];
int pre[801];
int d[801];
int n, e;

int dijkstra(int start, int end)
{
	fill(d + 1, d + n + 2, INF);
	fill(pre + 1, pre + n + 2, INF);

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	d[start] = 0;
	pq.push({ 0, start });

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
				pre[nxt.second] = cur.second;
				pq.push({ d[nxt.second], nxt.second });
			}
		}
	}
	return d[end];
}

signed main()
{

	cin >> n >> e;
	for (int i = 0;i < e;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}

	int v1, v2;
	cin >> v1 >> v2;
	int result = INF;
	
	int path1 = dijkstra(1, v1);
	int path2 = 0, path3 = 0;
	if (pre[v2])
	{
		path2 = dijkstra(v1, v2);
		path3 = dijkstra(v2, n);
	}
	else path3 = dijkstra(v1, n);

	if (path1 != INF && path2 != INF && path3 != INF)
	{
		result = min(result, path1 + path2+path3);
	}

	path1 = dijkstra(1, v2);
	path2 = 0, path3 = 0;
	if (pre[v1])
	{
		path2 = dijkstra(v2, v1);
		path3 = dijkstra(v1, n);
	}
	else path3 = dijkstra(v2, n);

	if (path1 != INF && path2 != INF && path3 != INF)
	{
		result = min(result, path1 + path2+path3);
	}
	
	if (result == INF) cout << -1;
	else cout << result;
	return 0;
}