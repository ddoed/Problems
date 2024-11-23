#include <iostream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	map<string,int> dic;
	vector<string> dic2;
	
	int n, m;
	cin >> n >> m;

	string x;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		dic.emplace(make_pair(x,i));
		dic2.push_back(x);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (isdigit(x[0]))
			cout << dic2[stoi(x) - 1] << '\n';
		else
			cout << dic[x] << endl;
	}
	return 0;
}