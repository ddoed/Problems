#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int h, n, q;
	cin >> h >> n >> q;

	long long sum = 0;

	for (int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		pq.push(x);
		sum += x;
	}
	int hp = h;

	if (h > sum) cout << -1 << '\n';
	else
	{ 
		int num = 0;
		while(hp < sum)
		{
			num = pq.top();
			sum -= pq.top();
			pq.pop();
		}
		if (hp != sum)
		{
			pq.push(num);
			sum += num;
		}
		cout << pq.size() << '\n';
	}

	for (int i = 0;i < q;i++)
	{
		int qNum;
		hp = h;
		cin >> qNum;
		pq.push(qNum);
		sum += qNum;

		if (h > sum) cout << -1 << '\n';
		else
		{
			int num = 0;
			while (hp < sum)
			{
				num = pq.top();
				sum -= pq.top();
				pq.pop();
			}
			if (hp != sum)
			{
				pq.push(num);
				sum += num;
			}
			cout << pq.size() << '\n';
		}
	}
	
	return 0;
}