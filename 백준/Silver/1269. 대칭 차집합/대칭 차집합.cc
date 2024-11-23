#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int aNum, bNum;
	int input;
	set<int> A;
	set<int> B;
	set<int> A_B;
	set<int> B_A;

	cin >> aNum >> bNum;
	for (int i = 0; i < aNum; i++)
	{
		cin >> input;
		A.insert(input);
	}
	for (int i = 0; i < bNum; i++)
	{
		cin >> input;
		B.insert(input);
	}

	set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(A_B, A_B.begin()));
	set_difference(B.begin(), B.end(), A.begin(), A.end(), inserter(B_A, B_A.begin()));

	cout << A_B.size() + B_A.size();
	return 0;
}