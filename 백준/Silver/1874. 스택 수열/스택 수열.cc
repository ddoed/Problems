#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s;
vector<string> result;

int main()
{
	int n;
	bool canMake = true;
	cin >> n;

	vector<int> v(n);
	for (int i = 0;i < n;i++)
	{
		cin >> v[i];
	}

	int num = 0;
	while (num != v[0])
	{
		num++;
		s.push(num);
		result.push_back("+");
	}
	s.pop();
	result.push_back("-");

	for (int i = 1;i < n;i++)
	{
		if (v[i] < v[i - 1])
		{
			if (s.top() == v[i])
			{
				s.pop();
				result.push_back("-");
			}
			else
			{
				canMake = false;
				break;
			}
		}
		else
		{
			while (num != v[i])
			{
				num++;
				s.push(num);
				result.push_back("+");
			}
			s.pop();
			result.push_back("-");
		}
	}

	if (canMake)
	{
		for (auto a : result)
		{
			cout << a << '\n';
		}
	}
	else
		cout << "NO";

	return 0;
}