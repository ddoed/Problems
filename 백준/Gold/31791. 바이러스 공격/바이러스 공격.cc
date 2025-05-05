#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

char city[1000][1000];
int visited[1000][1000] = { 0 };

priority_queue<tiii, vector<tiii>, greater<tiii>> virus;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int tg, tb, x, b;

bool cmp(pii p1, pii p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first < p2.first;
}

bool isValid(int nxtX, int nxtY)
{
	return nxtX >= 0 && nxtY >= 0 && nxtX < n && nxtY < m && visited[nxtX][nxtY] == 0;
}

void BFS()
{
	while (!virus.empty())
	{
		int x = get<1>(virus.top());
		int y = get<2>(virus.top());
		int time = get<0>(virus.top());
		virus.pop();
		visited[x][y] = 1;

		for (int i = 0;i < 4;i++)
		{
			int nxtX = x + dx[i];
			int nxtY = y + dy[i];
			if (isValid(nxtX, nxtY))
			{
				if (city[nxtX][nxtY] == '#')
				{
					visited[nxtX][nxtY] = 2;
					if (time + 1 + tb <= tg) virus.push({ time + 1 + tb, nxtX, nxtY });
				}
				else if (time + 1 <= tg)
				{
					virus.push({ time + 1, nxtX, nxtY });
					visited[nxtX][nxtY] = 1;
				}
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;
	cin >> tg >> tb >> x >> b;

	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;

		for (int j = 0;j < m;j++)
		{
			city[i][j] = s[j];
			if (s[j] == '*')
			{
				virus.push({ 0, i, j });
				visited[i][j] = 1;
			}
		}
	}

	BFS();
	vector<pii> pos;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (visited[i][j] != 1)
			{
				pos.push_back({ i,j });
			}
		}
	}
	if (pos.empty())
	{
		cout << -1;
		return 0;
	}

	sort(pos.begin(), pos.end(), cmp);

	for (auto p : pos)
	{
		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}

	return 0;
}