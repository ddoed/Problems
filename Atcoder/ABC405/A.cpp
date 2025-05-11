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
#include <climits>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, r;
	cin >> x >> r;

	if ((r == 1 && x >= 1600 && x <= 2999) || (r == 2 && x >= 1200 && x <= 2399))
	{
		cout << "Yes";
	}
	else cout << "No";

	return 0;
}