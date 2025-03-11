#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	vector<int> v(n, 0);
	vector<int> fruits(10, 0);

	for (int i = 0;i < n;i++)
	{
		cin >> v[i];
	}

	int start = 0, end = 0;
	int uniqueFruits = 0;
	while (end < n)
	{
		if (fruits[v[end]] == 0) uniqueFruits++;
		fruits[v[end]]++;
		while (uniqueFruits > 2)
		{
			fruits[v[start]]--;
			if (fruits[v[start]] == 0) uniqueFruits--;
			start++;
		}
		end++;
		cnt = max(cnt, end - start);
	}

	cout << cnt;
	
	return 0;
}