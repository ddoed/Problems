#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, B;
	cin >> N >> B;
	string s = "";
	
	while(N != 0)
	{
		if (N % B >= 10)
		{
			s += N % B - 10 + 'A';
		}
		else
		{
			s += N % B + '0';
		}
		N /= B;
	}

	reverse(s.begin(), s.end());
	cout << s;
	return 0;
}