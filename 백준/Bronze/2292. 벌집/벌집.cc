#include <iostream>

using namespace std;

int main()
{
	int cnt = 1;
	int layer = 1;
	int n;
	cin >> n;

	while (n > cnt)
	{
		cnt += 6 * layer;
		layer++;
	}
	cout << layer;
	return 0;
	
}