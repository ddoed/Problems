#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


bool seen[26][26] = { false };
vector<int> result;
int cnt = 0;
int n;
int house[26][26] = { 0 };

void HouseCount(int y,int x)
{
	cnt++;
	seen[y][x] = true;

	if (y - 1 >= 0 && !seen[y - 1][x] && house[y - 1][x])
	{
		HouseCount(y-1,x);
	}
	if (y+1 < n && !seen[y+1][x] && house[y + 1][x])
	{
		HouseCount(y+1,x);
	}
	if (x - 1 >= 0 && !seen[y][x-1] && house[y][x-1])
	{
		HouseCount(y,x-1);
	}
	if (x+1 < n && !seen[y][x+1] && house[y][x+1])
	{
		HouseCount(y,x+1);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string inputString;
		cin >> inputString;
		
		for (int j = 0; j < inputString.size(); j++)
		{
			house[i][j] = inputString[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!seen[i][j] && house[i][j] == 1)
			{
				cnt = 0;
				HouseCount(i,j);

				if (cnt != 0)
					result.push_back(cnt);
			}
		}
	}
	
	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}
}