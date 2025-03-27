#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	long long x;
	cin >> x;
	
	long long cnt = 0;
	long long layer = 1;

	while (cnt + layer < x)
	{
		cnt += layer;
		layer++;
	}

	long long left, right;

	if (layer % 2 == 0)
	{
		left = 0;
		right = layer + 1;
		long long r = x - cnt;
		left += r;
		right -= r;
	}
	else
	{
		left = layer + 1;
		right = 0;
		long long r = x - cnt;
		left -= r;
		right += r;
	}

	cout << left << '/' << right;

	return 0;
}