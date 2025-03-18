#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int arr[8] = { 0 };
bool visited[8] = { false };
int n, m;

void Print()
{
	for (int i = 0;i < m;i++)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';
}

void BT(int len)
{
	if (len == m)
	{
		Print();
		return;
	}

	int prev = -1;
	for (int i = 0;i < n;i++)
	{
		if (visited[i] || arr[i] == prev) continue;

		visited[i] = true;
		v.push_back(arr[i]);
		BT(len + 1);
		v.pop_back();
		visited[i] = false;

		prev = arr[i];
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	BT(0);

	return 0;
}