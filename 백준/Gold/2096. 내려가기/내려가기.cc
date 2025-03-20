#include <iostream>

using namespace std;
int dp[3][100001] = {0};
int maxSum[3][2] = {0};
int minSum[3][2] = {0};

int main()
{
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++)
	{
		cin >> dp[0][i] >> dp[1][i] >> dp[2][i];
	}

	for (int i = 1;i <= n;i++)
	{
		maxSum[0][1] = dp[0][i] + max(maxSum[0][0], maxSum[1][0]);
		maxSum[1][1] = dp[1][i] + max(maxSum[0][0], max(maxSum[1][0], maxSum[2][0]));
		maxSum[2][1] = dp[2][i] + max(maxSum[2][0], maxSum[1][0]);

		maxSum[0][0] = maxSum[0][1];
		maxSum[1][0] = maxSum[1][1];
		maxSum[2][0] = maxSum[2][1];

		minSum[0][1] = dp[0][i] + min(minSum[0][0], minSum[1][0]);
		minSum[1][1] = dp[1][i] + min(minSum[0][0], min(minSum[1][0], minSum[2][0]));
		minSum[2][1] = dp[2][i] + min(minSum[2][0], minSum[1][0]);

		minSum[0][0] = minSum[0][1];
		minSum[1][0] = minSum[1][1];
		minSum[2][0] = minSum[2][1];
	}

	cout << max(maxSum[0][1], max(maxSum[1][1], maxSum[2][1])) << ' ' << min(minSum[0][1], min(minSum[1][1], minSum[2][1]));

	return 0;
}