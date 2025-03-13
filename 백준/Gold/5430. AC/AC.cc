#include <iostream>
#include <deque>
#include <string>

using namespace std;

string func;
deque<int> dq;
int t, n;
bool isReversed;


void AC()
{
	for (int i = 0;i < func.size();i++)
	{
		if (func[i] == 'R')
		{
			isReversed = !isReversed;
		}
		else if (func[i] == 'D')
		{
			if (dq.size() == 0)
			{
				cout << "error" << '\n';
				return;
			}
			if (!isReversed) dq.pop_front();
			else dq.pop_back();
		}
	}
    
    if (dq.size() == 0)
    {
	    cout << "[]" << '\n';
	    return;
    }
		
	cout << '[';
	for (int i = 0;i < dq.size()-1;i++)
	{
		if (isReversed) cout << dq[dq.size() - 1 - i] << ',';
		else cout << dq[i] << ',';
	}
	if (isReversed) cout << dq[0] << ']' << '\n';
	else cout << dq[dq.size() - 1] << ']' << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;

	for (int i = 0;i < t;i++)
	{
		cin >> func;
		cin >> n;

		string s;
		cin >> s;
        
		isReversed = false;
		dq.clear();

		string num = "";
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] != '[' && s[i] != ']' && s[i] != ',')
			{
				num += s[i];
			}
			else if(!num.empty())
			{
				dq.push_back(stoi(num));
				num = "";
			}

		}
		AC();
	}
	
	return 0;
}