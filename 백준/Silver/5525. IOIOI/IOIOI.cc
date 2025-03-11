#include <iostream>

using namespace std;

int main()
{
	int n, m;
	string s;

	cin >> n >> m;
	cin >> s;

	int cnt = 0;
	int patternCnt = 0;

	for (int i = 0;i < m-2;i++)
	{
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			patternCnt++;
			if (patternCnt >= n) cnt++;
			i++;
		}
		else patternCnt = 0;
	}

	cout << cnt;

	return 0;
}