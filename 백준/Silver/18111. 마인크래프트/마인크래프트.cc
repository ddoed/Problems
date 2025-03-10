#include <iostream>

using namespace std;

int ground[500][500] = { 0 };
long long minTime = 64000000;
int maxHeight = -1;
int resultHeight;

int n, m;
long long b;


int make_plain(int floor, long long inventory)
{
	long long time = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (ground[i][j] != floor)
			{
				int blocks = abs(floor - ground[i][j]);
				if (ground[i][j] < floor)
				{
					time += blocks;
					inventory -= blocks;
				}
				else if (ground[i][j] > floor)
				{
					time += (blocks) * 2;
					inventory += blocks;
				}
			}
		}
	}
	if (inventory < 0) return -1;
	return time;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> b;
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> ground[i][j];
			maxHeight = max(maxHeight, ground[i][j]);
		}
	}

	while (maxHeight >= 0)
	{
		int t = make_plain(maxHeight, b);
		if (t != -1 && minTime > t)
		{
			resultHeight = maxHeight;
			minTime = t;
		}
		maxHeight--;
	}

	cout << minTime << ' ' << resultHeight;
	
	return 0;
}