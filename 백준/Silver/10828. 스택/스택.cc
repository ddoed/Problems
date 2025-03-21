#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

void Command(string s)
{
	if (s == "push")
	{
		int num;
		cin >> num;
		st.push(num);
	}
	else if (s == "pop")
	{
		if (st.empty()) cout << -1 << '\n';
		else
		{
			cout << st.top() << '\n';
			st.pop();
		}
	}
	else if (s == "size")
	{
		cout << st.size() << '\n';
	}
	else if (s == "empty")
	{
		if (st.empty())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	else if (s == "top")
	{
		if (st.empty()) cout << -1 << '\n';
		else cout << st.top() << '\n';
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;
		Command(s);
	}
	return 0;
}