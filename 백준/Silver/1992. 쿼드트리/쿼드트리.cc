#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int QuadTree[65][65] = { 0 };
vector<char> v;

bool IsUniform(pair<int, int> pos, int size, int& number)
{
	int x = pos.first, y = pos.second;
	number = QuadTree[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (QuadTree[i][j] != number) return false;
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
		v.push_back(number+'0');
	}
	else
	{
		v.push_back('(');
		Divide({ x,y }, size / 2);
		Divide({ x + size / 2,y }, size / 2);
		Divide({ x, y + size / 2 }, size / 2);
		Divide({ x + size / 2, y + size / 2 }, size / 2);
		v.push_back(')');
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < input.size(); j++)
		{
			QuadTree[i][j] = input[j] - '0';
		}
	}

	Divide({ 0,0 }, n);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
}