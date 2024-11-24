#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, start;

vector<vector<int>> graph(100001);
bool seen[100001] = { false };
int result[100001] = { 0 };
int cnt = 0;

bool Compare(int a, int b)
{
	return a > b;
}

void DFS(int idx)
{
	if (seen[idx]) return;

	seen[idx] = true;
	cnt++;
	result[idx] = cnt;

	for (int i = 0; i < graph[idx].size(); i++)
	{
		DFS(graph[idx][i]);
	}
}

int main()
{
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end(), Compare);
	}

	DFS(start);

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << '\n';
	}
}