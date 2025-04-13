#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32001];
int deg[32001] = { 0 };

queue<int> q;
vector<int> result;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	for (int i = 1;i <= n;i++)
	{
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (auto s : result)
	{
		cout << s << ' ';
	}
}