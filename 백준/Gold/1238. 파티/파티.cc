#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define pii pair<long long, long long>

vector<pii> adj[1001];
int goHome[1001];
int n, m, x;

int party(int st)
{
	int d[1001];
	fill(d + 1, d + n + 2, INF);

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	d[st] = 0;
	pq.push({ 0,st });

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
	return d[x];
}
signed main()
{
	cin >> n >> m >> x;
	fill(goHome + 1, goHome + n + 2, INF);

	for (int i = 0;i < m;i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back({ t, v });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	goHome[x] = 0;
	pq.push({ 0,x });

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		
		if (goHome[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second])
		{
			if (goHome[nxt.second] > goHome[cur.second] + nxt.first)
			{
				goHome[nxt.second] = goHome[cur.second] + nxt.first;
				pq.push({ goHome[nxt.second], nxt.second });
			}
		}
	}
	
	int maxTime = 0;
	for (int i = 1;i <= n;i++)
	{
		if (goHome[i] == INF || party(i) == INF) continue;
		int total = party(i) + goHome[i];
		maxTime = max(maxTime, total);
	}

	cout << maxTime;


	return 0;
}