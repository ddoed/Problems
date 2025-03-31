#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{

	ios::sync_with_stdio(0); cin.tie(0);
	int n, t;
	long long maxDrink = 0;
	vector<pair<long long, long long>> v;
	cin >> n >> t;
	
	for (int i = 0;i < n;i++)
	{
		int l, r;
		cin >> l >> r;
		maxDrink += r;
		v.push_back({l,r});
	}

	if (maxDrink < t)
	{
		cout << -1;
		return 0;
	}

	long long left = 1;
	long long right = t;
	long long mid;
	long long result = -1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		long long maxS = 0;
		long long minS = 0;
		bool stop = false;
		
		for (int i = 0;i < n;i++)
		{
			long long good = v[i].first;
			long long bad = v[i].second;

			if (good > mid)
			{
				left = mid + 1;
				stop = true;
				break;
			}
			maxS += min(bad, mid);
			minS += good;
		}

		if (!stop)
		{
			if (maxS >= t && minS <= t)
			{
				right = mid - 1;
				result = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	cout << result;
	

	return 0;
}