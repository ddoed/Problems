#include <iostream>
#include <vector>
using namespace std;

int n;
bool seen[100001] = { false };
vector<vector<int>> v(100001);
int arr[100001] = { 0 };

void DFS(int num)
{
	seen[num] = true;
	for (int i = 0;i < v[num].size();i++)
	{
		int next = v[num][i];
		if (!seen[next])
		{
			arr[next] = num;
			DFS(next);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0;i < n - 1;i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);

	for (int i = 2;i <= n;i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}