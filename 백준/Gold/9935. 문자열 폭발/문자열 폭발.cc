#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <stack>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str, bomb;
	string temp = "";
	cin >> str >> bomb;
	int bombLen = bomb.size();

	for (int i = 0;i < str.size();i++)
	{
		temp += str[i];
		if (temp.size() >= bombLen)
		{
			bool flag = true;
			for (int j = 0;j < bombLen;j++)
			{
				if (temp[temp.size() - bombLen + j] != bomb[j])
				{
					flag = false;
				}
			}
			if (flag)
			{
				temp.erase(temp.size() - bombLen, temp.size());
			}
		}
	}

	if (temp.empty()) cout << "FRULA";
	else cout << temp;
	

	return 0;
}

