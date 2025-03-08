#include <iostream>
#include <vector>

using namespace std;

bool is_prime(long long num)
{
	if (num < 2) return false;
	for (int i = 2; i * i <= num;i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 1;i <= 2000000;i++)
	{
		vector<int> v;
		bool valid = true;

		for (int j = 0;j < n;j++)
		{
			int num = i + j * m;
			if (is_prime(num))
			{
				valid = false;
				break;
			}
			v.push_back(num);
		}

		if (valid)
		{
			for (int i = 0;i < n;i++)
			{
				cout << v[i] << ' ';
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}