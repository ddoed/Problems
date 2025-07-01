#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

vector<int> a;
vector<int> b;

signed main() {
	int n, m;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int in;
		cin >> in;
		a.push_back(in);
	}
	cin >> m;
	for (int i = 0;i < m;i++) {
		int in;
		cin >> in;
		b.push_back(in);
	}

	vector<int> ans;
	bool flag = false;
	while (a.size() != 0 && b.size() != 0) {
		int temp = 0;
		int ai = 0, bi = 0;
		for (int i = 0;i < a.size();i++) {
			for (int j = 0;j < b.size();j++) {
				if (a[i] == b[j] && temp < a[i]) {
					temp = max(temp, a[i]);
					ai = i;bi = j;
					continue;
				}
			}
		}
		if (!temp) break;
		flag = true;
		ans.push_back(temp);
		a.erase(a.begin(), a.begin() + ai+1);
		b.erase(b.begin(), b.begin() + bi+1);
	}
	cout << ans.size() << '\n';
	if (flag) for (auto an : ans) cout << an << ' ';
}