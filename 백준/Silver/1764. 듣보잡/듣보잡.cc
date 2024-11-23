#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;
	string name;
	set<string> notHeard;
	set<string> notSeen;
	set<string> notHS;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> name;
		notHeard.insert(name);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> name;
		notSeen.insert(name);
	}

	set_intersection(notHeard.begin(), notHeard.end(), notSeen.begin(), notSeen.end(), inserter(notHS, notHS.begin()));

	cout << notHS.size() << '\n';
	for (string name : notHS)
	{
		cout << name << '\n';
	}

	return 0;
}