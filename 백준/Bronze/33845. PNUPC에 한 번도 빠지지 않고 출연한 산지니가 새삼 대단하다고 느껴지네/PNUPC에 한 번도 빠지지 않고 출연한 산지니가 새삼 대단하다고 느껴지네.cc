#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>
#include <cstring>
#include <string>

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

	string s, t;
	cin >> s >> t;
	string result = "";

	for (int i = 0;i < t.size();i++)
	{
		if (s.find(t[i]) == string::npos)
		{
			result += t[i];
		}
	}
	cout << result;

	return 0;
}