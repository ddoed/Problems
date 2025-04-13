#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
int deg[1001] = { 0 };
queue<int> q;
vector<int> result;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0;i < m;i++)
	{
		int x;
		cin >> x;
		int pnum = -1;
		for (int j = 0;j < x;j++)
		{
			int num;
			cin >> num;
			if (pnum == -1)
			{
				pnum = num;
				continue;
			}
			adj[pnum].push_back(num);
			deg[num]++;
			pnum = num;
		}
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

	if (result.size() != n) cout << 0;
	else for (int s : result) cout << s << '\n';
}