#include <iostream>
#include <algorithm>

using namespace std;

int paper[129][129] = { 0 };
int Bcnt = 0;
int Wcnt = 0;

void Divide(pair<int,int> pos, int num)
{
	int sum = 0;
	int x = pos.first, y = pos.second;
	for (int i = y; i < y + num; i++)
	{
		for (int j = x; j < x + num; j++)
		{
			sum += paper[i][j];
		}
	}

	if (sum == num * num)
		Bcnt++;
	else if (sum == 0)
		Wcnt++;
	else
	{
		Divide({x,y}, num/2);
		Divide({x + num/2,y}, num / 2);
		Divide({x, y + num/2}, num / 2);
		Divide({ x + num / 2, y + num / 2 }, num / 2);
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

	Divide({0,0}, n);

	cout << Wcnt << '\n' << Bcnt;
}