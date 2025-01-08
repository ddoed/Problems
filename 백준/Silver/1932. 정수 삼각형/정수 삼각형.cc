#include <iostream>

using namespace std;

int main()
{
	int n,m = 0;
	int arr[501][501] = {0};
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		if (i == 0)
		{
			cin >> arr[0][0];
			m = arr[0][0];
			continue;
		}
		for (int j = 0;j <= i;j++)
		{
			cin >> arr[i][j];
			if (j == 0) arr[i][j] += arr[i - 1][j];
			else if (j == i) arr[i][j] += arr[i - 1][j - 1];
			else arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
			if (m < arr[i][j]) m = arr[i][j];
		}
	}
	cout << m;

	return 0;
}