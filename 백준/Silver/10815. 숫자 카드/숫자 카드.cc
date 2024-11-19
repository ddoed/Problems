#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,x,m;
	unordered_set<int> s;
	vector<int> vec;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s.emplace(x);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (s.find(x) == s.end())
			vec.push_back(0);
		else
			vec.push_back(1);
	}

	for (int i = 0; i < m; i++)
	{
		cout << vec[i] << " ";
	}

	
	return 0;
}