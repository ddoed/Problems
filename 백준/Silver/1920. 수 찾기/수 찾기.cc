#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n, m, input;
	unordered_set<int> s;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> input;
		s.emplace(input);
	}
	cin >> m;
	for (int i = 0;i < m;i++)
	{
		cin >> input;
		if (s.find(input) != s.end()) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}