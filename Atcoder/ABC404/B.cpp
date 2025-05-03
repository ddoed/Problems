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

int n;

vector<vector<int>> rotate90(vector<vector<int>>& s)
{
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			v[j][n - 1 - i] = s[i][j];
		}
	}
	return v;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<vector<int>> s(n, vector<int>(n, 0));
	vector<vector<int>> t(n, vector<int>(n, 0));

	for (int i = 0;i < n;i++)
	{
		string str;
		cin >> str;
		for (int j = 0;j < n;j++)
		{
			s[i][j] = str[j];
		}
	}

	for (int i = 0;i < n;i++)
	{
		string str;
		cin >> str;
		for (int j = 0;j < n;j++)
		{
			t[i][j] = str[j];
		}
	}

	int minCnt = INF;
	for (int i = 0;i < 4;i++)
	{
		int cnt = i;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (s[i][j] != t[i][j]) cnt++;
			}
		}
		vector<vector<int>> v = rotate90(s);
		s = v;
		minCnt = min(cnt, minCnt);
	}
	cout << minCnt;

	return 0;
}