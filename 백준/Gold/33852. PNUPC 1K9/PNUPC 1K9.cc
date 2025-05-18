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
	int k, p;
	cin >> s >> k >> p;

	for (auto& e : s) {
		if (e <= '9') e -= '0';
		else e -= 'A' - 10;
	}

	int n = s.size();
	int x = 1;
	vector<int> pows(n);
	for (int i = n-1; i >= 0; i--)
	{
		pows[i] = x;
		x = x * 36 % p;
	}

	int original = 0;
	for (int i = 0; i < n;i++) {
		original = (original + pows[i] * s[i]) % p;
	}

	if (original == k) {
		cout << 0;
		return 0;
	}

	bool flag = false;
	for (int i = 0; !flag && i < n; i++) {
		for (int j = 0; !flag && j < 36;j++) {
			int cur = (original + (j - s[i]) * pows[i]) % p;
			if (cur < 0) cur += p;
			flag = (cur == k);
		}
	}
	if (flag) {
		cout << 1;
		return 0;
	}
	cout << (n == 1 ? -1 : 2);
}
