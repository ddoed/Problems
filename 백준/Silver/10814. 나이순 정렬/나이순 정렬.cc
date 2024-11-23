#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct myPair
{
	int first;
	string second;
	int idx;
}myPair;

bool Compare(myPair a, myPair b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.idx < b.idx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,age,idx;
	string name;
	vector<myPair> v;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		idx = i;
		v.push_back({ age,name,idx });
	}

	sort(v.begin(), v.end(), Compare);

	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	
	return 0;
}