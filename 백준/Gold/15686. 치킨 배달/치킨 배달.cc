#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m;
vector<tuple<int, int, int>> house;
vector<pair<int, int>> chicken;
bool visited[13] = { false };
int chickenPath = 50001;
int sum = 0;

void BT(int len, int start)
{
	if (len == m)
	{
		sum = 0;
		for (int i = 0;i < house.size();i++)
		{
			sum += get<2>(house[i]);
		}
		chickenPath = min(chickenPath, sum);
		return;
	}

	for (int i = start;i < chicken.size();i++)
	{
		if (visited[i]) continue;

		int cx = chicken[i].first;
		int cy = chicken[i].second;
		vector<int> prev;

		visited[i] = true;
		for (int j = 0;j < house.size();j++)
		{
			int hx = get<0>(house[j]);
			int hy = get<1>(house[j]);
			int minPath = get<2>(house[j]);
			prev.push_back(minPath);
			minPath = min(minPath, abs(cx - hx) + abs(cy - hy));
			get<2>(house[j]) = minPath;
		}
		BT(len + 1, i);
		visited[i] = false;
		for (int i = 0;i < house.size();i++)
		{
			get<2>(house[i]) = prev[i];
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1; j <= n;j++)
		{
			int input;
			cin >> input;
			if (input == 1) house.push_back({ i,j, 51 });
			if (input == 2) chicken.push_back({ i,j });
		}
	}
	BT(0, 0);

	cout << chickenPath;

	return 0;
}