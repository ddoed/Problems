#include <iostream>

using namespace std;

int main()
{
	int n;
	int money;
	int quarter, dime, nickel, penny;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> money;
		quarter = 0, dime = 0, nickel = 0, penny = 0;

		quarter = money / 25;
		dime = money % 25 / 10;
		nickel = money % 25 % 10 / 5;
		penny = money%25%10%5/1;
		cout << quarter << " " << dime << " " << nickel << " " << penny << endl;
	}
}