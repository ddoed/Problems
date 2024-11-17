#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;



void Command(int num)
{
	int input;
	switch (num)
	{
		case 1:
		{
			cin >> input;
			dq.push_front(input);
			break;
		}
		case 2:
		{
			cin >> input;
			dq.push_back(input);
			break;
		}
		case 3:
		{
			if (!dq.empty())
			{
				cout << dq.front() << '\n';
				dq.pop_front();
				
			}
			else
				cout << -1 << '\n';
			break;
		}
		case 4:
		{
			if (!dq.empty())
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << -1 << '\n';
			break;
		}
		case 5:
		{
			cout << dq.size() << '\n';
			break;
		}
		case 6:
		{
			if (dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		}
		case 7:
		{
			if (!dq.empty()) cout << dq.front() << '\n';
			else cout << -1 << '\n';
			break;
		}
		case 8:
		{
			if (!dq.empty()) cout << dq.back() << '\n';
			else cout << -1 << '\n';
			break;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	int input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		Command(input);
	}
	return 0;
}