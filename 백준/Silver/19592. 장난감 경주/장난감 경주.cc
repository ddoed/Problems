#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, x, y, t, myV;
	
	cin >> t;


	while (t--)
	{
		double minTime = 1000001;
		cin >> n >> x >> y;

		for (int i = 0;i < n-1;i++)
		{
			int v;
			cin >> v;
			minTime = min(minTime, (double)x / v);
		}
		cin >> myV;
		double myTime = (double)x / myV;
		if (myTime < minTime)
		{
			cout << 0 << '\n';
			continue;
		}
		else if ((x - y) / myV+1 >= minTime)
		{
			cout << -1 << '\n';
			continue;
		}
		else
		{
			int left = 1;
			int right = y;
			int mid = (1+y)/2;

			while (left <= right)
			{
				double BoosterTime = ((double)(x - mid) / myV) + 1;
				if (BoosterTime >= minTime) left = mid + 1;
				else right = mid - 1;
				mid = (left + right) / 2;
			}

			cout << mid+1 << '\n';
		}
	}

	return 0;
}