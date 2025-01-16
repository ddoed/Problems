#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int len[27][200001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	char ch;
	int q,l,r;
	cin >> s >> q;

	for (int i = 1;i <= s.size();i++)
	{
		for (int j = 0;j < 27;j++)
		{
			len[j][i] = len[j][i - 1];
		}
		len[s[i-1] - 'a'][i]++;
	}

	for (int i = 0;i < q;i++)
	{
		cin >> ch >> l >> r;

		cout << len[ch - 'a'][r + 1] - len[ch - 'a'][l] << '\n';
	}

	return 0;
}