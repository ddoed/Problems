#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int n;
int comb[11] = { 0, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1 };
int cnt = 0;
bool visited[10];
int len;

void DFS(int st, int size) {
	if (size == len) {
		if (cnt == n) {
			for (int i = 9;i >= 0;i--) {
				if (visited[i]) cout << i;
			}
			exit(0);
		}
		else cnt++;
		return;
	}
	for (int i = 0;i < st;i++) {
		visited[i] = true;
		DFS(i, size + 1);
		visited[i] = false;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	int sum = 0;
	for (int i = 0;i < 11;i++) {
		comb[i] += sum;
		sum = comb[i];
	}
	for (int i = 1;i < 11;i++) {
		if (n < comb[i]) {
			len = i;
			cnt = comb[i - 1];
			DFS(10, 0);
		}
	}
	cout << -1;
}
