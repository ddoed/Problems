#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;

	while (t--)
	{
		int k;
		cin >> k;
		multiset<int> ms;

		for (int i = 0;i < k;i++)
		{
			string cmd;
			int n;
			cin >> cmd >> n;

			if (cmd == "I") ms.insert(n);
			else if (!ms.empty())
			{
				if (n == 1) ms.erase(prev(ms.end()));
				else if (n == -1) ms.erase(ms.begin());
			}
		}

		if (ms.empty()) 
		{
			cout << "EMPTY" << '\n';
		}
		else 
		{
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
		}
	}

	return 0;
}