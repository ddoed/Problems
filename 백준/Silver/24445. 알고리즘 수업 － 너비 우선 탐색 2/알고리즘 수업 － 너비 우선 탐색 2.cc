#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, start;

vector<vector<int>> graph(100001);
queue<int> q;
bool seen[100001] = { false };
int result[100001] = { 0 };
int cnt = 0;

bool Compare(int a, int b)
{
	return a > b;
}

void BFS(int idx)
{
    q.push(idx);
    seen[idx] = true;
    cnt++;
    result[idx] = cnt;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if (!seen[next])
            {
                seen[next] = true;
                cnt++;
                result[next] = cnt;
                q.push(next);
            }
        }
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

	BFS(start);

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << '\n';
	}
}