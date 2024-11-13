#include <iostream>

using namespace std;

int main()
{
	int left;
	int right;
	int layer = 1;
	int cnt=1;
	int x;
	cin >> x;

	while (x > cnt)
	{
		cnt += layer+1;
		layer++;
	}

	if (layer % 2 == 0)
	{
		left = layer;
		right = 1;
		while (cnt != x)
		{
			left--;
			right++;
			cnt--;
		}
	}
	else
	{
		left = 1;
		right = layer;
		while (cnt != x)
		{
			left++;
			right--;
			cnt--;
		}
	}
	cout << left << "/" << right << endl;


	return 0;
}