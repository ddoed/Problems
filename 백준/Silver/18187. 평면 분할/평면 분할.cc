#include <iostream>

using namespace std;

int dp[101] = { 0 };

int main()
{
	int n,result=0;
	cin >> n;

	dp[1] = 2; if (n == 1) result = 2;
	dp[2] = 2; if (n == 2) result = 4;
	dp[3] = 3; if (n == 3) result = 7;
	dp[4] = 3; if (n == 4) result = 10;

	int sum = 10;
	for (int i = 5;i <= n;i++)
	{
		dp[i] = dp[i - 3] + 2;
		sum += dp[i];
		result = sum;
	}
	cout << result;
	return 0;
}