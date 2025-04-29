#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

vector<int> p(51, -1);
vector<int> party[51];

signed main()
{
	int n, m;
	cin >> n >> m;

	int x;
	cin >> x;
	for (int i = 0;i < x;i++)
	{
		int num;
		cin >> num;
		p[num] = 0;
	}

	for (int i = 0;i < m;i++)
	{
		int num;
		cin >> x;
		for (int j = 0;j < x;j++)
		{
			cin >> num;
			party[i].push_back(num);
		}
	}

	bool updated = true;
	while (updated)
	{
		updated = false;
		for (int i = 0;i < m;i++)
		{
			bool flag = false;
			for (auto person : party[i])
			{
				if (p[person] == 0)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				for (auto person : party[i])
				{
					if (p[person] != 0)
					{
						p[person] = 0;
						updated = true;
					}
				}
			}
		}
	}
	

	int cnt = 0;
	for (int i = 0;i < m;i++)
	{
		bool flag = false;
		for (int j = 0;j < party[i].size();j++)
		{
			if (p[party[i][j]] == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag) cnt++;
	}
	cout << cnt;

	return 0;
}

