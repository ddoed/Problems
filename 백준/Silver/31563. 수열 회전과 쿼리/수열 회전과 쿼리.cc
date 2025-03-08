#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long> v(n, 0);

	for (int i = 0;i < n;i++)
	{
		cin >> v[i];
		if (i>0) v[i] += v[i - 1];
	}

	int num, k;
	long long idx = 0;
	for (int i = 0;i < q;i++)
	{
		cin >> num;

		if (num == 1)
		{
			cin >> k;
			idx -= k;
			idx += n;
			if (idx >= n) idx %= n;
		}
		else if (num == 2)
		{
			cin >> k;
			idx += k;
			idx %= n;
		}
		else if (num == 3)
		{
			int a, b;
			long long sum = 0;
			cin >> a >> b;
			a--;
			b--;

			a = (a+idx)%n;
			b = (b+idx)%n;

			if (a <= b)
			{
				if (a == 0) cout << v[b] << '\n';
				else cout << v[b] - v[a-1] << '\n';
			}
			else if (a > b)
			{
				cout << (v[n-1] - v[a-1] + v[b]) << '\n';
			}
		}
	}
	
	return 0;
}