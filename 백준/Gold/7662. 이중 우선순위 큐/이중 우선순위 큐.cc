#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while(t--)
	{
		int k;
		priority_queue<int> maxQ;
		priority_queue<int, vector<int>, greater<int>> minQ;
		unordered_map<int, int> cnt;

		cin >> k;
		int n;
		string cmd;

		while(k--)
		{
			cin >> cmd >> n;
			if (cmd == "I")
			{
				minQ.push(n);
				maxQ.push(n);
				cnt[n]++;
			}
			else if (cmd == "D")
			{
				if (n == 1)
				{
					while (!maxQ.empty() && cnt[maxQ.top()] == 0) maxQ.pop();

					if (!maxQ.empty())
					{
						cnt[maxQ.top()]--;
						maxQ.pop();
					}
				}
				if (n==-1)
				{
					while (!minQ.empty() && cnt[minQ.top()] == 0) minQ.pop();

					if (!minQ.empty())
					{
						cnt[minQ.top()]--;
						minQ.pop();
					}
				}
			}
		}

		while (!maxQ.empty() && cnt[maxQ.top()] == 0)
			maxQ.pop();
		while (!minQ.empty() && cnt[minQ.top()] == 0)
			minQ.pop();


		if (maxQ.empty() || minQ.empty())
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << maxQ.top() << ' ' << minQ.top() << '\n';
		}
	}

	return 0;
}