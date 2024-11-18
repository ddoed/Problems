#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	int n,x;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(make_pair(abs(x),x));
		}
	}
	return 0;
}