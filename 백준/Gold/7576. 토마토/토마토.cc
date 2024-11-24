#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m,n,x,y;
int seen[1001][1001] = { 0 };
vector<pair<int, int>> wt;
int cnt = 0;


pair<int, int> delta[4] = { {-1,0}, {1,0}, {0,1}, {0,-1} };

void BFS()
{
	queue<pair<int,int>> q;
	
	for (int i = 0; i < wt.size(); i++)
	{
		q.push({ wt[i].first, wt[i].second });
		seen[wt[i].second][wt[i].first] = 1;
	}

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + delta[i].first;
			int ny = curY + delta[i].second;

			if (nx >= 0 && ny >= 0 && nx < m && ny < n && seen[ny][nx] == 0)
			{
				q.push({ nx,ny });
				seen[ny][nx] = seen[curY][curX]+1;
			}
		}
	}
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;

			if (input == -1)
				seen[i][j] = -1;
			if (input == 1)
				wt.push_back({ j,i });
		}
	}
	
	BFS();

	bool allWarm = true;
	int max=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (seen[i][j] == 0)
			{
				allWarm = false;
			}
			if (seen[i][j] > max)
				max = seen[i][j];
		}
	}

	if (allWarm)
		cout << max-1;
	else
		cout << -1;
	
}