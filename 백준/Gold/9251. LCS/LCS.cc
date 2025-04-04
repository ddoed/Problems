#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001] = { 0 };

int main()
{
	int m=0;
	string s1,s2;
	cin >> s1 >> s2;

	for (int i = 1;i <= s1.size();i++)
	{
		for (int j = 1;j <= s2.size();j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
			m = max(m, dp[i][j]);
		}
	}
	cout << m;

	return 0;
}