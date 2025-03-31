#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	double r;
	vector<int> f;
	cin >> n >> m >> r;
	vector<int> p;
	unordered_map<int, int> um;
	vector<int> width;

	for (int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		p.push_back(x);

		for (int j = 0;j < p.size();j++)
		{
			int w = abs(p[i] - p[j]);
			if (w == 0) continue;
			if (um[w] == 0)
			{
				um[w]++;
				width.push_back(w);
			}
		}
	}

	for (int i = 0;i < m;i++)
	{
		int x;
		cin >> x;
		f.push_back(x);
	}

	sort(width.begin(), width.end());
	sort(f.begin(), f.end());

	double result = -1;

	for(int i=0;i<width.size();i++)
	{
		int w = width[i];
		double fl = ((2.0) * r) / w;

		int left = 0, right = f.size() - 1;
		int mid = -1;

		while (left <= right)
		{
			mid = (left + right) / 2;
			fl = 2.0 * r / w;

			if (f[mid] > fl)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
				double area = w * f[mid] / 2.0;
				result = max(result, area);
			}
		}
		
	}
	if (result > 0)
	{
		cout << fixed;
		cout.precision(1);
		cout << result;
	}
	else
	{
		cout << -1;
	}
	

	return 0;
}