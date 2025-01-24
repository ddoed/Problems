#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long house[1000001] = { 0 };
long long maxValue, minValue, midValue;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	long long cnt, phouse, ans=0;
	cin >> n >> c;

	for (int i = 0;i < n;i++)
	{
		cin >> house[i];
	}
	sort(house, house + n);
	maxValue = house[n - 1] - house[0];
	minValue = 1;

	while (minValue <= maxValue)
	{
		midValue = (minValue + maxValue) / 2;
		cnt = 1;
		phouse = house[0];

		for (int i = 1;i < n;i++)
		{
			if ((house[i] - phouse) >= midValue)
			{
				cnt++;
				phouse = house[i];
			}
		}
		if (cnt >= c)
		{
			minValue = midValue + 1;
			ans = max(ans, midValue);
		}
		else
		{
			maxValue = midValue - 1;
		}
	}
	cout << ans;

	return 0;
}