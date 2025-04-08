#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
unordered_map<string, int> um;
string name[1001];
int deg[1001] = { 0 };
vector<int> root;
vector<int> child[1001];

int main()
{
	int n, m;
	cin >> n;


	for (int i = 0;i < n;i++)
	{
		cin >> name[i];
	}
	sort(name, name + n);

	for (int i = 0;i < n;i++)
	{
		um[name[i]] = i;
	}

	cin >> m;
	for (int i = 0;i < m;i++)
	{
		string x, y;
		cin >> x >> y;

		adj[um[y]].push_back(um[x]);
		deg[um[x]]++;
	}

	for (int i = 0;i < n;i++)
	{
		if (deg[i] == 0)
		{
			root.push_back(i);
		}
	}

	cout << root.size() << '\n';
	for (auto r : root) cout << name[r] << ' ';
	cout << '\n';
	for (int i = 0;i < n;i++)
	{
		sort(adj[i].begin(), adj[i].end());
		for (auto c : adj[i])
		{
			if (deg[c] - deg[i] == 1) child[i].push_back(c);
		}
	}

	for (int i = 0;i < n;i++)
	{
		cout << name[i] << ' ' << child[i].size() << ' ';
		for (int c : child[i]) cout << name[c] << ' ';
		cout << '\n';
	}
}