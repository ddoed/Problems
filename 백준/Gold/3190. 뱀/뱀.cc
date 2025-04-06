#include <iostream>
#include <deque>
#include <queue>
#include <unordered_set>

using namespace std;

int board[101][101] = { 0 };
bool body[101][101] = { false };
queue<pair<int, char>> dir;
deque<pair<int,int>> snake;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 0;i < k;i++)
	{
		int row, col;
		cin >> row >> col;
		board[row][col] = 1;
	}

	int l;
	cin >> l;
	for (int i = 0;i < l;i++)
	{
		int x;
		char c;
		cin >> x >> c;
		dir.push({ x, c });
	}

	int time = 0;
	snake.push_back({ 1,1 });
	body[1][1] = true;
	char curDir = 'R';

	while (true)
	{
		time++;

		int headX = snake.front().first;
		int headY = snake.front().second;

		if (curDir == 'L') headX--;
		else if (curDir == 'R') headX++;
		else if (curDir == 'N') headY--;
		else if (curDir == 'S') headY++;

		if (headX > n || headX < 1 || headY > n || headY < 1 || body[headY][headX])
		{
			cout << time;
			break;
		}

		snake.push_front({headX, headY});
		body[headY][headX] = true;

		if (board[headY][headX] == 1)
		{
			board[headY][headX] = 0;
		}
		else
		{
			int tailX = snake.back().first;
			int tailY = snake.back().second;
			body[tailY][tailX] = false;
			snake.pop_back();
		}

		if (!dir.empty() && dir.front().first == time)
		{
			char ch = dir.front().second;
			dir.pop();
			if (ch == 'L')
			{
				if (curDir == 'L') curDir = 'S';
				else if (curDir == 'R') curDir = 'N';
				else if (curDir == 'N') curDir = 'L';
				else if (curDir == 'S') curDir = 'R';
			}
			else if (ch == 'D')
			{
				if (curDir == 'L') curDir = 'N';
				else if (curDir == 'R') curDir = 'S';
				else if (curDir == 'N') curDir = 'R';
				else if (curDir == 'S') curDir = 'L';
			}
		}
	}

	return 0;
}