#include <iostream>
#include <set>

using namespace std;

set<int> se;

void Command(string s)
{
	int num;
	if (s == "add")
	{
		cin >> num;
		se.insert(num);
	}
	else if (s == "remove")
	{
		cin >> num;
		se.erase(num);
	}
	else if (s == "check")
	{
		cin >> num;
		if (se.find(num) != se.end()) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	else if (s == "toggle")
	{
		cin >> num;
		if (se.find(num) != se.end()) se.erase(num);
		else se.insert(num);
	}
	else if (s == "all")
	{
		se = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	}
	else if (s == "empty")
	{
		se.clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;
		Command(s);
	}

	return 0;
}