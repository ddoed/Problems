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

	int n;
	cin >> n;
	vector<int> a(n + 1);

	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int total = 0;
	for (int i = 1;i <= n;i++)
	{
		total += a[i] * (sum - a[i]);
	}
	cout << total / 2;

	return 0;
}