#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INT_MAX 1000000000;

int arr[100001] = { 0 };
int sums[100001] = { 0 };

int main()
{
	int n,k,m = -1 * INT_MAX;
	cin >> n >> k;

	for (int i = 1;i <= n;i++)
	{
		cin >> arr[i];
		sums[i] = sums[i-1] + arr[i];
	}

	for (int i = 1;i <= n;i++)
	{
		if (i + k - 1 > n) break;
		m = max(m, sums[i + k - 1] - sums[i - 1]);
	}
	cout << m;


	return 0;
}