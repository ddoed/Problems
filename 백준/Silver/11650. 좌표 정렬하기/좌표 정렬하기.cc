#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,x,y;
	cin >> n;
	vector<pair<int, int>> pos;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		pos.push_back({ x,y });
	}

	sort(pos.begin(), pos.end());

	for (int i = 0; i < n; i++)
	{
		cout << pos[i].first << ' ' << pos[i].second << '\n';
	}
	
	return 0;
}