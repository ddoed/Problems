#include <iostream>

using namespace std;

int board[50][50] = { 0 };
int n, m;

int repaintW()
{
	int minPaint = n*m;
	for (int k = 0;k + 7 < n;k++)
	{
		for (int l = 0;l + 7 < m;l++)
		{
			int paint = 0;
			for (int i = k;i < k + 8;i++)
			{
				for (int j = l;j < l + 8;j++)
				{
					if ((i + j) % 2 == board[i][j])
					{
						paint++;
					}
				}
			}
			minPaint = min(paint, minPaint);
		}
	}
	return minPaint;
}

int repaintB()
{
	int minPaint = n * m;
	for (int k = 0;k + 7 < n;k++)
	{
		for (int l = 0;l + 7 < m;l++)
		{
			int paint = 0;
			for (int i = k;i < k + 8;i++)
			{
				for (int j = l;j < l + 8;j++)
				{
					if ((i + j) % 2 != board[i][j])
					{
						paint++;
					}
				}
			}
			minPaint = min(paint, minPaint);
		}
	}
	return minPaint;
}

int main()
{
	cin >> n >> m;

	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;

		for (int j = 0;j < m;j++)
		{
			if (s[j] == 'W') board[i][j] = 1;
			else board[i][j] = 0;
		}
	}

	int result = min(repaintW(), repaintB());
	cout << result;

	return 0;
}