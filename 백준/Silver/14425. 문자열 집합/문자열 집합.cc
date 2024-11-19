#include <iostream>
#include <unordered_set>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	unordered_set<string> s;
	
	int n, m;
	string x;
	int count = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s.emplace(x);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (s.find(x) != s.end())
			count++;
	}
	cout << count << '\n';

	return 0;
}