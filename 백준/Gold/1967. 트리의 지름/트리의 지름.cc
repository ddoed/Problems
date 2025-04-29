#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

vector<pii> adj[10001];
bool visited[10001] = { false };
int farNode;
int maxDist;

void DFS(int node, int dist)
{
	visited[node] = true;
	if (dist > maxDist)
	{
		maxDist = dist;
		farNode = node;
	}

	for (auto p : adj[node])
	{
		if (!visited[p.second])
		{
			DFS(p.second, dist + p.first);
		}
	}
}

signed main()
{
	int n;
	cin >> n;

	for (int i = 0;i < n - 1;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
		adj[v].push_back({ w,u });
	}

	DFS(1, 0);

	fill(visited, visited + n + 1, false);
	maxDist = 0;
	DFS(farNode, 0);

	cout << maxDist;
	
	return 0;
}

