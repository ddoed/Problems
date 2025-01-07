#include <iostream>

using namespace std;

long long dp[101] = { 0 };

long long DP(int n)
{
    if (dp[n] != 0)
    {
        return dp[n];
    }
    dp[n] = DP(n - 1) + DP(n - 5);
    return dp[n];
}


int main() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    int n,t;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> t;
        cout << DP(t) << '\n';
    }

    return 0;
}