#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long Modpow(long long a, long long b, long long c)
{
	if (b == 0)
		return 1;
	else
	{
		long long temp = Modpow(a, b / 2,c);
		temp = temp * temp % c;
		if (b%2 == 0)
			return (temp);
		else
			return (temp * a)%c;
	}
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;

	cout << Modpow(a,b,c);
}