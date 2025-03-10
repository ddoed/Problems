#include <iostream>
#include <queue>

using namespace std;

char school[600][600] = { 0 };
bool seen[600][600] = { false };
queue<pair<int,int>> q;
int n, m;
pair<int, int> delta[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int cnt = 0;

void BFS()
{
	while (!q.empty())
	{
		for (int k = 0;k < 4;k++)
		{
			int dy = q.front().first + delta[k].first;
			int dx = q.front().second + delta[k].second;
			
			if (dy < n && dx < m && dy >= 0 && dx >= 0 && !seen[dy][dx])
			{
				seen[dy][dx] = true;
				if (school[dy][dx] != 'X') q.push({ dy,dx });
				if (school[dy][dx] == 'P') cnt++;
			}
		}
		q.pop();
	}
	
}

int main()
{

	cin >> n >> m;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> school[i][j];
			if (school[i][j] == 'I')
			{
				q.push({ i,j });
				seen[i][j] = true;
			}
		}
	}

	BFS();

	if (cnt == 0) cout << "TT";
	else cout << cnt;

	return 0;
}