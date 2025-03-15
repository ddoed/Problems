#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

#define MAX 10000

int a, b, x;
unordered_map<int, string> m;

string BFS()
{
	bool seen[10000] = { false };
	m.clear();
	queue<int> q;
	q.push(a);
	seen[a] = true;
	while (!q.empty())
	{
		int num = q.front();
		string cmd = m[num];
		q.pop();
		
		x = (num * 2) % 10000;
		if (x >= 0 && !seen[x])
		{
			seen[x] = true;
			string s = cmd + "D";
			m[x] = s;
			q.push(x);
			if (x == b) return s;
		}
		
		if (num == 0) x = 9999;
		else x = (num - 1) % 10000;
		if (x >= 0 && !seen[x])
		{
			seen[x] = true;
			string s = cmd + "S";
			m[x] = s;
			q.push(x);
			if (x == b) return s;
		}
		
		x = ((num % 1000) * 10 + num / 1000) % 10000;
		if (x >= 0 && !seen[x])
		{
			seen[x] = true;
			string s = cmd + "L";
			m[x] = s;
			q.push(x);
			if (x == b) return s;
		}
		
		x = ((num % 10) * 1000 + num / 10) % 10000;
		if (x >= 0 && !seen[x])
		{
			seen[x] = true;
			string s = cmd + "R";
			m[x] = s;
			q.push(x);
			if (x == b) return s;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> a >> b;
		cout << BFS() << '\n';
	}

	return 0;
}