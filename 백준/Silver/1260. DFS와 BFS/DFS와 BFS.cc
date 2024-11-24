#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, start;

vector<vector<int>> graph(100001);
queue<int> q;
bool seen1[100001] = { false };
bool seen2[100001] = { false };
int resultDFS[100001] = { 0 };
int resultBFS[100001] = { 0 };
int cnt1 = 0;
int cnt2 = 0;

void DFS(int idx)
{
    if (seen1[idx]) return;

    seen1[idx] = true;
    cnt1++;
    resultDFS[cnt1] = idx;

    for (int i = 0; i < graph[idx].size(); i++)
    {
        int current = graph[idx][i];
        DFS(current);
    }
}

void BFS(int idx)
{
    q.push(idx);
    seen2[idx] = true;
    cnt2++;
    resultBFS[cnt2] = idx;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if (!seen2[next])
            {
                seen2[next] = true;
                cnt2++;
                resultBFS[cnt2] = next;
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
		sort(graph[i].begin(), graph[i].end());
	}

    DFS(start);
	BFS(start);

	for (int i = 1; i <= cnt1; i++)
	{
		cout << resultDFS[i] << ' ';
	}
    cout << '\n';
    for (int i = 1; i <= cnt2; i++)
    {
        cout << resultBFS[i] << ' ';
    }
}