#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n;
	cin >> n;

	if (n % 7 == 0 || n % 7 == 2)
	{
		cout << "CY";
	}
	else 
	{
		cout << "SK";
	}
	
	return 0;
}