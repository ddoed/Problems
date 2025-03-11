#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int result = 500000;

vector<vector<int>> v(101);

int Bacon(int i)
{
	bool seen[101] = { false };
	queue<int> q;
	seen[i] = true;
	int idx = 1;
	int sum = 0;
	q.push(i);

	while (!q.empty())
	{
		int qSize = q.size();
		for (int k = 0;k < qSize;k++)
		{
			int person = q.front();
			q.pop();
			for (int j = 0;j < v[person].size();j++)
			{
				int num = v[person][j];
				if (!seen[num])
				{
					seen[num] = true;
					q.push(v[person][j]);
					sum += idx;
				}
			}
		}
		idx++;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int minPerson = 0;

	for (int i = 1;i <= n;i++)
	{
		int baconNumber = Bacon(i);
		if (baconNumber < result)
		{
			minPerson = i;
			result = baconNumber;	
		}
	}

	cout << minPerson;
	
	return 0;
}