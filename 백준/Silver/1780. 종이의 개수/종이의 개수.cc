#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int paper[2188][2188] = { 0 };
int minusCnt = 0;
int zeroCnt = 0;
int plusCnt = 0;

bool IsUniform(pair<int, int> pos, int size, int& number)
{
	int x = pos.first, y = pos.second;
	number = paper[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (paper[i][j] != number) return false;
		}
	}
	return true;
}

void Divide(pair<int, int> pos, int size)
{
	int x = pos.first, y = pos.second;
	int number;
	if (IsUniform(pos,size,number))
	{
		if (number == 1)
			plusCnt++;
		else if (number == 0)
			zeroCnt++;
		else
			minusCnt++;
	}
	else
	{
		int delta = size / 3;
		Divide({ x,y }, delta);
		Divide({ x + delta,y }, delta);
		Divide({ x + delta*2,y }, delta);
		
		Divide({ x, y + delta }, delta);
		Divide({ x + delta, y + delta }, delta);
		Divide({ x + delta*2, y + delta }, delta);

		Divide({ x, y + delta*2 }, delta);
		Divide({ x + delta, y + delta*2 }, delta);
		Divide({ x + delta*2, y + delta*2 }, delta);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}

	Divide({ 0,0 }, n);

	cout << minusCnt << '\n' << zeroCnt << '\n' << plusCnt;
}