#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int seen[100001] = { 0 };
queue<int> q;
int n, k;

void BFS(int x)
{
	q.push(x);
	seen[x] = true;

	while (!q.empty())
	{
		int cur = q.front();
		if (cur == k)
			break;
		q.pop();

		if (cur - 1 >= 0 && seen[cur-1] == 0)
		{
			seen[cur - 1] = seen[cur] + 1;
			q.push(cur - 1);
		}
		if (cur < 100001 && seen[cur + 1] == 0)
		{
			seen[cur + 1] = seen[cur] + 1;
			q.push(cur + 1);
		}
		if (cur * 2 < 100001 && seen[2 * cur] == 0)
		{
			seen[cur * 2] = seen[cur] + 1;
			q.push(cur*2);
		}
	}
}

int main()
{
	cin >> n >> k;

	BFS(n);

	cout << seen[k]-1;
}