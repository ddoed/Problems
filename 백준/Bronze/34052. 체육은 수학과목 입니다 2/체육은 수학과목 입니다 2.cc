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
	int sum = 0;
	for (int i = 0;i < 4;i++) {
		int x;
		cin >> x;
		sum += x;
	}
	if (1800 - sum < 300) cout << "No";
	else cout << "Yes";
}