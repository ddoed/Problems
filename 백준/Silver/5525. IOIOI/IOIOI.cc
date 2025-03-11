#include <iostream>

using namespace std;

int main()
{
	int n, m;
	string s;
	string findS = "I";

	cin >> n >> m;
	cin >> s;

	for (int i = 0;i < n;i++)
	{
		findS += "OI";
	}
	int startIdx = 0;
	int cnt = 0;
	while(startIdx < s.size())
	{
		auto x = s.find(findS, startIdx);
		if (x != string::npos)
		{
			startIdx = x + 2;
			cnt++;
		}
		else break;
	}

	cout << cnt;

	return 0;
}