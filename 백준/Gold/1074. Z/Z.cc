#include <iostream>

using namespace std;

int n, r, c;
long long cnt = 0;

void Order(int i, int j, int size)
{
	if (size == 1) 
	{
		if (i == r && j == c)
		{
			cout << cnt;
			exit(0);
		}
		cnt++;
		return;
	}

	int half = size / 2;

	if (r < i + half && c < j + half)
	{
		Order(i, j, half);
	}
	else if (r < i + half && c >= j+half)
	{
		cnt += half * half;
		Order(i, j + half, half);
	}
	else if (r >= i+half && c < j+half)
	{
		cnt += half * half * 2;
		Order(i + half, j, half);
	}
	else if (r >= i+half && c >= j+half)
	{
		cnt += half * half * 3;
		Order(i + half, j+half, half);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> r >> c;

	Order(0, 0, 1 << n);
	
	return 0;
}