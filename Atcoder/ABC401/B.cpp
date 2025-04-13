#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define pii pair<long long, long long>

signed main()
{
	int n;
	int cnt = 0;
	cin >> n;
	string ps = "logout";
	string ps2 = "";
	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;

		if (s == "login") ps = "login";
		else if (s == "logout") ps = "logout";
		else if (s == "public") ps2 = "public";
		else if (s == "private")
		{
			ps2 = "private";
			if (ps == "logout" && ps2 == "private") cnt++;
		}

	}
	cout << cnt;


	return 0;
}