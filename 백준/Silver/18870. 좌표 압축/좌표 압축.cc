#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back({ a,i });
	}
	
	sort(v.begin(), v.end());

	int count = 0;

	for (int i = 1; i < n; i++)
	{
		if (v[i - 1].first != v[i].first)
			v[i - 1].first = count++;
		else
			v[i - 1].first = count;
	}
	v[n - 1].first = count;

	sort(v.begin(), v.end(), Compare);

	for (auto p : v)
		cout << p.first << ' ';

	return 0;
}