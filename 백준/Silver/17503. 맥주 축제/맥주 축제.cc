#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
vector<pair<int, int>> beers;

int main()
{
	cin >> n >> m >> k;

	for (int i = 0;i < k;i++)
	{
		long long like, alcol;
		cin >> like >> alcol;
		beers.push_back({ alcol, like });
	}

	sort(beers.begin(), beers.end());

	priority_queue<int, vector<int>, greater<>> pq;

	long long sum = 0;
	for (auto beer : beers)
	{
		pq.push(beer.second);
		sum += beer.second;

		if (pq.size() > n)
		{
			sum -= pq.top();
			pq.pop();
		}

		if (pq.size() == n && sum >= m)
		{
			cout << beer.first;
			return 0;
		}
	}
	cout << -1;

	return 0;
}