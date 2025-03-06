#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



int main()
{
	int t, n;
	cin >> t;
	for (int j = 0;j < t;j++)
	{
		unordered_map<string, vector<string>> clothes;
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			string category, name;
			cin >> name >> category;

			if (clothes.find(category) == clothes.end())
			{
				clothes.insert({ category, vector<string>() });	
			}
			clothes[category].push_back(name);
		}
		int result = 1;
		for (auto c : clothes)
		{
			result *= c.second.size()+1;
		}
		result--;
		cout << result << '\n';
	}

	return 0;
}