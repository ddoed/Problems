#include <iostream>
#include <queue>

using namespace std;

int board[101] = { 0 };
bool seen[101] = { false };
queue<int> q;
int n, m;
int cnt = 0;

void BFS()
{
	q.push(1);
	seen[1] = true;
	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0;i < qSize;i++)
		{
			int num = q.front();
			q.pop();
			for (int j = 1;j <= 6;j++)
			{
				int dx = num + j;
				if (!seen[dx])
				{
					seen[dx] = true;
					if (dx == 100 || board[dx] == 100)
					{
						cnt++;
						return;
					}
					if (board[dx] != 0)
					{
						q.push(board[dx]);
					}
					else if (dx < 100) q.push(dx);
				}
			}
		}
		cnt++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0;i < n + m;i++)
	{
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}

	BFS();

	cout << cnt;

	return 0;
}