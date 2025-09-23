#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

int priority(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	stack<char> s;
	cin >> str;

	for (auto c : str) {
		if (c >= 'A' && c <= 'Z') {
			cout << c;
		}
		else {
			if (s.empty() || c == '(') s.push(c);
			else if (c == ')') {
				while (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.pop();
			}
			else {
				while (!s.empty() && priority(s.top()) >= priority(c)) {
					cout << s.top();
					s.pop();
				}
				s.push(c);
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}