#include <iostream>
#include <queue>

using namespace std;

long long a, b;
queue<pair<long long,int>> q;
bool flag = false;

void BFS()
{
	q.push({ a, 0 });
	while (!q.empty())
	{
		pair<long long,int> front = q.front();
		long long num = front.first;
		int cnt = front.second;
		q.pop();

		if (num * 2 == b || num * 10 + 1 == b)
		{
			flag = true;
			cout << cnt + 2;
			break;
		}
		if (num * 2 < b) q.push({ num * 2, cnt + 1 });
		if (num * 10 + 1 < b) q.push({ num * 10 + 1, cnt+1 });
	}
}

int main()
{
	cin >> a >> b;

	BFS();

	if (!flag) cout << -1;

	return 0;
}