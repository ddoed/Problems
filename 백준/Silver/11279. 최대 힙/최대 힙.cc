#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	priority_queue<int> pq;
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
				cout << pq.top() << '\n';
				pq.pop();
			}
			
		}
		else
			pq.push(x);
	}
	return 0;
}