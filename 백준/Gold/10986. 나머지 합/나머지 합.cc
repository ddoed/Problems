#include <iostream>

using namespace std;

long long mod[1001] = { 0 };

int main()
{
	int n, m, input;
	long long sums = 0, cnt = 0;
	cin >> n >> m;

	for (int i = 1;i <= n;i++)
	{
		cin >> input;
		sums += input;
		mod[sums % m]++;
	}

	for (int i = 0;i <= m;i++)
	{
		long long n = mod[i];
		cnt += ((n - 1) * n) / 2;
	}
	cout << cnt + mod[0];

	return 0;
}