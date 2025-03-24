#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int t, k;
	
	cin >> t;

	while (t--)
	{
		cin >> k;
		priority_queue<long long, vector<long long>, greater<long long>> chapters;
		long long sum = 0;
		for (int i = 0;i < k;i++)
		{
			int x;
			cin >> x;
			chapters.push(x);
		}

		while (chapters.size() > 1) 
		{
			long long one = chapters.top();
			chapters.pop();
			long long two = chapters.top();
			chapters.pop();

			sum += (one + two);
			chapters.push(one + two);
		}

		cout << sum << '\n';
	}

	return 0;
}