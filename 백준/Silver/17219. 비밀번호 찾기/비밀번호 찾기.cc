#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> memo;

int main()
{
	int n,m;
	string address;
	string pwd;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> address >> pwd;
		memo.insert({ address, pwd });
	}
	for (int i = 0;i < m;i++)
	{
		cin >> address;
		cout << memo[address] << '\n';
	}


	return 0;
}