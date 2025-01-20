#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arrA[101][101] = { 0 };
int arrB[101][101] = { 0 };
int newArr[101][101] = { 0 };

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arrA[i][j];
		}
	}

	int k;
	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> arrB[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int k = 0; k < m; k++)
			{
				newArr[i][j] += arrA[i][k] * arrB[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << newArr[i][j] << ' ';
		}
		cout << '\n';
	}
}