#include <iostream>
#include <vector>

using namespace std;

int grape[10001] = { 0 };
int sums[10001] = { 0 };

int main()
{
	int n;
	cin >> n;

	cin >> grape[1] >> grape[2];
	sums[1] = grape[1];
	sums[2] = grape[1] + grape[2];

	for (int i = 3;i <= n;i++)
	{
		cin >> grape[i];
		sums[i] = max(grape[i] + sums[i - 2], max(grape[i] + grape[i - 1] + sums[i - 3], sums[i - 1]));
	}
	cout << sums[n];

	return 0;
}