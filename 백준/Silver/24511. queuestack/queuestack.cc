#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n;
	vector<int> type(n);
	deque<int> dq;
	
	for (int i = 0; i < n; i++)
	{
		cin >> type[i];
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (type[i] == 0)
			dq.push_back(x);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		dq.push_front(input);
		cout << dq.back() << " ";
		dq.pop_back();
	}

	return 0;
}