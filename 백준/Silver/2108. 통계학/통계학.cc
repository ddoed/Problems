#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int counts[8001] = { 0 };

int main()
{
	int n;
	cin >> n;

	double sum = 0;
	vector<int> v;
	int maxCount = 0;
	int minV = 4001;
	int maxV = -4001;

	for (int i = 0;i < n;i++)
	{
		int input;
		cin >> input;
		sum += input;
		v.push_back(input);
		counts[input + 4000]++;
		minV = min(minV, input);
		maxV = max(maxV, input);
	}

	int average = round(sum / n);

	sort(v.begin(), v.end());
	int mid;
	if (n % 2 == 0)
	{
		mid = (v[(n / 2)-1] + v[n / 2]) / 2;
	}
	else
	{
		mid = v[(n-1) / 2];
	}

	vector<int> modes;

	for (int i = 0;i < 8001;i++)
	{
		if (counts[i] > maxCount)
		{
			maxCount = counts[i];
			modes.clear();
			modes.push_back(i - 4000);
		}
		else if (counts[i] == maxCount)
		{
			modes.push_back(i - 4000);
		}
	}

	int mode;
	if (modes.size() == 1)
		mode = modes[0];
	else
		mode = modes[1];

	int range = maxV - minV;

	cout << average << '\n';
	cout << mid << '\n';
	cout << mode << '\n';
	cout << range << '\n';

	return 0;
}