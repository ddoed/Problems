#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sums[1025][1025] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long m;
	cin >> n >> m;

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> sums[i][j];
			sums[i][j] += sums[i][j - 1];
		}
	}

	for (int i = 0;i < m;i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			cout << sums[x2][y2] - sums[x1][y1 - 1] << '\n';
			continue;
		}
		else
		{
			int a = 0;
			for (int i = x1;i <= x2;i++)
			{
				a += sums[i][y2] - sums[i][y1 - 1];
			}
			cout << a << '\n';
		}
		
	}

	return 0;
}