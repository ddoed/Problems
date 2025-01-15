#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001] = { 0 };

int main()
{
	int n,m;
	cin >> n >> m;
	cin >> arr[1];
	for (int i = 2;i <= n;i++)
	{
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
	}

	for (int i = 0;i < m;i++)
	{
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		printf("%d\n", arr[a2] - arr[a1 - 1]);
	}
	return 0;
}