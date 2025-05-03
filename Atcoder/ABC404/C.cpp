#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>
#include <cstring>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

vector<int> adj[200001];
bool visited[200001] = { false };

void DFS(int node)
{
	visited[node] = true;
	for (auto nxt : adj[node])
	{
		if (visited[nxt]) continue;
		DFS(nxt);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if (n != m)
	{
		cout << "No";
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		if (adj[i].size() != 2)
		{
			cout << "No";
			return 0;
		}
	}

	DFS(1);

	for (int i = 1;i <= n;i++)
	{
		if (!visited[i])
		{
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";

	return 0;
}