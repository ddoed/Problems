#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	long long input;
	long long m = 0;
	vector<long long> v;

	cin >> k >> n;

	for (int i = 0;i < k;i++)
	{
		cin >> input;
		v.push_back(input);
		m = max(m, input);
	}

	long long left, right, mid;
	left = 1;
	right = m;
	long long ans = 0;
	
	while (left <= right)
	{
		mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0;i < v.size();i++)
		{
			cnt += v[i] / mid;
		}
		if (cnt >= n)
		{
			left = mid + 1;
			ans = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	
	return 0;
}