#include <iostream>
#include <unordered_set>
#include <algorithm>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	unordered_set<string> s;
	
	int n;
	cin >> n;

	string name;
	string log;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		cin >> log;

		if (log == "enter")
			s.emplace(name);
		else if (log == "leave")
			s.erase(name);
	}

	vector<string> vec(s.begin(), s.end());
	sort(vec.rbegin(), vec.rend());
	
	for (auto it : vec)
	{
		cout << it << '\n';
	}
	

	return 0;
}