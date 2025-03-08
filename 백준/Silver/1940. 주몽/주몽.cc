#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int used[15000] = { false };

int main()
{
	long long m;
	int n;
	int cnt;
	cin >> n;
	cin >> m;

	vector<int> v(n);
	
	for (int i = 0;i < n;i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cnt = 0;
	int left = 0, right = n - 1;

	while (left < right) {
		int sum = v[left] + v[right];

		if (sum == m) {
			cnt++;
			left++;
			right--; 
		}
		else if (sum < m) {
			left++; 
		}
		else {
			right--;
		}
	}

	cout << cnt;
	

	return 0;
}