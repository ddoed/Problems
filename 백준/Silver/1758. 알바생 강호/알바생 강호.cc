#include <iostream>
#include <algorithm>

using namespace std;

int tip[100001] = { 0 }; 

int main()
{
	long long tipSum = 0, n;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> tip[i];
	}
	sort(tip, tip + n, greater<int>());
	for (int i = 0;i < n;i++)
	{
		
		tip[i] = tip[i] - i;
		if (tip[i] <= 0) continue;
		else tipSum += tip[i];
	}

	cout << tipSum;

	return 0;
}