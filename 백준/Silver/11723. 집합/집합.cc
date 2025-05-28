#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int a = 0;

void Command(string& s) {
	int x;
	if (s == "add") {
		cin >> x;
		a |= (1 << x);
	}
	else if (s == "remove") {
		cin >> x;
		a &= ~(1 << x);
	}
	else if (s == "check") {
		cin >> x;
		cout << ((a & (1 << x)) ? 1 : 0) << '\n';
	}
	else if (s == "toggle") {
		cin >> x;
		a ^= (1 << x);
	}
	else if (s == "all") {
		a |= (1 << 21) -1;
	}
	else if (s == "empty") {
		a = 0;
	}
}       

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		string in;
		cin >> in;
		Command(in);
	}
}
