#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

bool visited[100001] = { false };
priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	pq.push({ 0, n });

	int minTime = INF;
	int cnt = 0;
	while (!pq.empty())
	{
		auto t = pq.top();
		pq.pop();

		int time = t.first;
		int x = t.second;
		visited[x] = true;
		if (x == k)
		{
			if (minTime > time)
			{
				cnt = 1;
				minTime = time;
			}
			else if (minTime == time) cnt++;
		}
		if (2 * x >= 0 && 2 * x <= 100000 && !visited[2 * x]) pq.push({ time + 1, 2 * x });
		if (x + 1 >= 0 && x + 1 <= 100000 && !visited[x + 1]) pq.push({ time + 1, x + 1 });
		if (x - 1 >= 0 && x - 1 <= 100000 && !visited[x - 1]) pq.push({ time + 1, x - 1 });
	}

	cout << minTime << '\n' << cnt;

	return 0;
}