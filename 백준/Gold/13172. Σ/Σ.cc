#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>
#include <cstring>
#include <string>
#include <numeric> // gcd

using namespace std;

#define MOD 1000000007
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

int modPow(int a, int b)
{
	if (b == 0) return 1;
	int temp = modPow(a, b / 2) % MOD;

	if (b % 2 == 0) return temp * temp % MOD;
	else return (temp * temp % MOD) * (a%MOD) % MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> m;

	int sum = 0;
	for (int i = 0;i < m;i++)
	{
		int n, s;
		cin >> n >> s;

		int g = gcd(n, s);
		s /= g;
		n /= g;
		
		int inverse = modPow(n, MOD-2);
		int mod = s * inverse % MOD;
		sum += mod;
		sum %= MOD;
	}
	cout << sum;

	return 0;
}