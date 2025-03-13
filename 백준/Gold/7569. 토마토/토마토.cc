#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

bool seen[100][100][100] = { false };
int tomato[100][100][100] = { 0 };
int n, m, h;
int days = 0;
int totalTomato = 0;
int cnt = 0;
queue<tuple<int, int, int>> q;
tuple<int, int, int> delta[6] = { {0,-1,0}, {0,1,0}, {0,0,1}, {0,0,-1}, {-1,0,0}, {1,0,0} };

void BFS()
{
	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0;i < qsize;i++)
		{
			tuple<int, int, int> num = q.front();
			q.pop();

			for (auto t : delta)
			{
				int dx = get<0>(num) + get<0>(t);
				int dy = get<1>(num) + get<1>(t);
				int dz = get<2>(num) + get<2>(t);

				if (dx < h && dx >= 0 && dy < m && dy >= 0 && dz < n && dz >= 0 && !seen[dx][dy][dz] && tomato[dx][dy][dz] != -1)
				{
					seen[dx][dy][dz] = true;
					tomato[dx][dy][dz] = 1;
					q.push({ dx,dy,dz });
					cnt++;
				}
			}
		}
		days++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> h;

	int x=0, y=0, z=0;

	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < m;j++)
		{
			for (int k = 0;k < n;k++)
			{
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
				{
					q.push({ i,j,k });
					seen[i][j][k] = true;
					cnt++;
				}
				if(tomato[i][j][k] != -1) totalTomato++;
			}
		}
	}

	BFS();

	if (cnt != totalTomato) cout << -1;
	else cout << days-1;
	
	return 0;
}