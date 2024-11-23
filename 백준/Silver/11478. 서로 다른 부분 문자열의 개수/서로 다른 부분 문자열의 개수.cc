#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	set<string> s;
	string strings;
	cin >> strings;

	for (int i = 1; i <= strings.size(); i++)
	{
		for (int j = 0; strings[j+i-1] != '\0'; j++)
		{
			s.insert(strings.substr(j, i));
		}
	}

	cout << s.size();
	
	
	return 0;
}