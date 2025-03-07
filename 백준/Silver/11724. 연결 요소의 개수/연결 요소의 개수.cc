#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix(1001);
bool seen[1001] = {false};

int cnt = 0;
int n, m;

void DFS(int i)
{
	seen[i] = true;
	for (int j = 0;j < matrix[i].size();j++)
	{
		if (!seen[matrix[i][j]])
			DFS(matrix[i][j]);
	}
}

int main()
{
	int u,v;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		cin >> u >> v;
		matrix[u].push_back(v);
		matrix[v].push_back(u);
	}

	for (int i = 1;i <= n;i++)
	{
		if (!seen[i])
		{
			DFS(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}