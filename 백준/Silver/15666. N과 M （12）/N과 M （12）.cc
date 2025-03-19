#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m;
int arr[8] = { 0 };
bool visited[8] = { false };
int p = -1;

void Print()
{
	for (int i = 0;i < v.size();i++)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';
}

void BT(int len, int start)
{
	if (len == m)
	{
		Print();
		return;
	}

	for (int i = start;i < n;i++)
	{
		if (p == arr[i]) continue;

		v.push_back(arr[i]);
		BT(len + 1, i);
		v.pop_back();

		p = arr[i];
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

	BT(0, 0);

	return 0;
}