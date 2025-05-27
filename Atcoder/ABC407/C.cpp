#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int bPress = 0;
	int cnt = 0;
	for (int i = s.size() - 1;i >= 0;i--) {
		int num = ((s[i] - '0' - bPress) % 10 + 10) % 10;
		bPress += num;
		cnt += num + 1;
	}
	cout << cnt;
}
