#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

long long modular_pow(long long a, long long p)
{
	if (a == 1 || p == 0) return 1;
	
	long long half = modular_pow(a, p / 2);
	half = (half * half) % MOD;
	if (p%2 != 0) half = (half * a) % MOD;
    return half;
}
	

int main()
{
	long long n, k, a=1, b=1;
	cin >> n >> k;

	for (int i = n;i >= n - k + 1;i--)
	{
		a = (a * i) % MOD;
	}
	for (int i = 2;i <= k;i++)
	{
		b = (b * i) % MOD;
	}
	cout << (a * modular_pow(b, MOD - 2)) % MOD;

	return 0;
}