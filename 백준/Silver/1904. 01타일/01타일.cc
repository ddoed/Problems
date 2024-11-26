#include <iostream>

using namespace std;
int dp[1000001] = { 0 };

int count(int n)
{
	if (dp[n] != 0)
		return dp[n] % 15746;

	dp[n] = count(n - 1) + count(n - 2);
	return dp[n]%15746;
}

int main()
{
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	dp[5] = 8;

	cout << count(n);

	return 0;
}