#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { 0,-1, 0,1 };
int dy[4] = { 1, 0, -1, 0 };

signed main() {
	int n, m;
	int cnt = 0;
	bool flag = false;
	int minNum = INF;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int x;
			cin >> x;
			minNum = min(minNum, x);
			cnt += x;
			if (x == 0) flag = true;
		}
	}
	cout << cnt - minNum;
}