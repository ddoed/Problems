#include <iostream>
#include <cstring>

using namespace std;

int t, n;
int sticker[2][100002] = { 0 };

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n;
		memset(sticker, 0, sizeof(sticker));
		for (int i = 0;i <= 1;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				cin >> sticker[i][j];
			}
		}

		for (int i = 2;i <= n + 1;i++)
		{
			sticker[0][i] = sticker[0][i] + max(sticker[1][i - 1], max(sticker[0][i - 2], sticker[1][i - 2]));
			sticker[1][i] = sticker[1][i] + max(sticker[0][i - 1], max(sticker[1][i - 2], sticker[0][i - 2]));
		}
		cout << max(sticker[0][n + 1], sticker[1][n + 1]) << '\n';
	}
	return 0;
}