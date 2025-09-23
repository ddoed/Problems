#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

vector<pii> adj[100001];
bool visited[100001] = { false };

int maxLen = -1;
int farNode;

void dfs(int num, int len) {
	visited[num] = true;
	if (len > maxLen) {
		maxLen = len;
		farNode = num;
	}
	for (auto [l, nxt] : adj[num]) {
		if (!visited[nxt]) {
			dfs(nxt, len + l);
		}
	}

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v;
	cin >> v;
	for (int i = 0;i < v;i++) {
		int num, other, len;
		cin >> num;
		while (true) {
			cin >> other;
			if (other == -1) break;
			cin >> len;
			adj[num].push_back({ len, other });
		}
	}

	dfs(1, 0);
	fill(visited, visited + v+1, false);
	dfs(farNode, 0);
	cout << maxLen;
}