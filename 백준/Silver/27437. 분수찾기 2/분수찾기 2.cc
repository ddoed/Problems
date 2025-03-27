#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	long long x;
	cin >> x;
	
	long long cnt = 0;
	long long layer = 1;

	// 개수를 더하면서 현재 x의 layer 찾기
	while (cnt + layer < x)
	{
		cnt += layer;
		layer++;
	}

	long long left, right;

	// 짝수일 경우 왼쪽 아래에서 오른쪽 위로
	if (layer % 2 == 0)
	{
		left = 0;
		right = layer + 1;
		long long r = x - cnt;
		// 남은 개수만큼 더하고 뺀다
		left += r;
		right -= r;
	}
	else // 홀수일 경우 오른쪽 위에서 왼쪽 아래로
	{
		left = layer + 1;
		right = 0;
		long long r = x - cnt;
		left -= r;
		right += r;
	}

	cout << left << '/' << right;

	return 0;
}