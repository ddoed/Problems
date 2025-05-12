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
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t;
	cin >> n >> t;

	vector<int> v(n);
	for (int i = 0;i < n;i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.begin() + t);

	for (int i = 0;i < n;i++) cout << v[i] << ' ';

	return 0;
}