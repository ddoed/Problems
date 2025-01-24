#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	long long n, m, maxValue = 0, len, result=0;
	cin >> n >> m;
	vector<long long> v(n);

	for (int i = 0;i < n;i++)
	{
		cin >> v[i];
		maxValue = max(maxValue, v[i]);
	}

	long long left = 1;
	long long right = maxValue;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		len = 0;
		for (int i = 0;i < n;i++)
		{
			if (v[i] > mid)
			{
				len += v[i] - mid;
			}
		}
		if (len < m)
		{
			right = mid - 1;
		}
		else if (len >= m)
		{
			result = mid;
			left = mid + 1;
		}
	}
	cout << result;

	return 0;
}