#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>
#include <cstring>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	for (int i = 0;i < 26;i++)
	{
		char ch = 'a' + i;
		if (s.find(ch) == string::npos)
		{
			cout << ch;
			break;
		}
	}

	return 0;
}