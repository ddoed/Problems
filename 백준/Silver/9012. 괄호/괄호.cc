#include <iostream>
#include <stack>

using namespace std;

int main() {

    int n;
    string ps;
    cin >> n;

    for (int i = 0;i < n;i++)
    {
        stack<char> s;
        cin >> ps;
        for (char i : ps)
        {
            if (i == '(')
                s.push('(');
            else if (i == ')')
            {
                if (!s.empty())
                    s.pop();
                else
                {
                    s.push('(');
                    break;
                }
            }
                
        }
        if (s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}