#include <iostream>
#include <string>

using namespace std;

void findN(int n)
{
	int cnt = 0;
	int i = 666;
	
	while (true)
	{
		string s = to_string(i);
		for (int j = 0;j < s.size() - 2;j++)
		{
			if (s[j] == '6' && s[j + 1] == '6' && s[j + 2] == '6')
			{
				cnt++;
				if (cnt == n)
				{
					cout << i;
					return;
				}
				break;
			}
		}
		i++;
	}
	
}

int main()
{
	int n;
	cin >> n;

	findN(n);


	return 0;
}