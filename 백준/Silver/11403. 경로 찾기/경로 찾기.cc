#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> v(100);

void DFS(int node, int visited[])
{
	for(int i=0;i<v[node].size();i++)
	{
		int current = v[node][i];
		if (!visited[current])
		{
			visited[current] = 1;
			DFS(current, visited);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			int x;
			cin >> x;

			if (x == 1) v[i].push_back(j);
		}
	}

	for (int i = 0;i < n;i++)
	{
		int visited[100] = { 0 };
		DFS(i, visited);
		for (int j = 0;j < n;j++)
		{
			cout << visited[j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}