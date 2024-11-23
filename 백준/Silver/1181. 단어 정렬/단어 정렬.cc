#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool Compare(const string& a, const string& b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	else
		return a < b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string input;
	set<string> word;
	
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		word.insert(input);
	}

	vector<string> vecWord(word.begin(), word.end());
	sort(vecWord.begin(), vecWord.end(), Compare);

	for (string s : vecWord)
	{
		cout << s << '\n';
	}
	
	return 0;
}