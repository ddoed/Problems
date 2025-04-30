#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

char star[3072][6144];

void printStar(int x, int y, int n)
{
	if (n == 3)
	{
		star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 1][y + 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y-1] = '*';
		star[x + 2][y-2] = '*';
		star[x + 2][y+1] = '*';
		star[x + 2][y+2] = '*';
	}
	else
	{
		printStar(x, y, n / 2);
		printStar(x + n / 2, y - n / 2, n / 2);
		printStar(x + n / 2, y + n / 2, n / 2);
	}
}


signed main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 2*n - 1;j++)
		{
			star[i][j] = ' ';
		}
	}
	printStar(0, n-1, n);

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 2 * n - 1;j++)
		{
			cout << star[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}

