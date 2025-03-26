#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool flag;
int visited[20001] = { 0 };

void DFS(vector<vector<int>>& graph, int n, int color)
{
	visited[n] = color;
	for (int i = 0; i < graph[n].size();i++)
	{
		int next = graph[n][i];
		if (visited[next] == 0)
		{
			DFS(graph, next, -color);
		}
		else if (visited[next] == color)
		{
			flag = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int k;
	cin >> k;
	while (k--)
	{
		int n, e;
		vector<vector<int>> graph(20001);
		fill(visited, visited + 20001, 0);
		
		flag = true;
		cin >> n >> e;

		for (int i = 0;i < e;i++)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1;i <= n;i++)
		{
			if (visited[i] == 0)
			{
				DFS(graph, i, 1);
			}
		}

		if (flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}