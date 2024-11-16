#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    while (true)
    {
        stack<char> stack;
        string s;
        getline(cin, s);

        if (s == ".") break;

        for (char ch : s)
        {
            if (ch == '[' || ch == '(')
                stack.push(ch);
            else if (ch == ']')
            {
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else
                {
                    stack.push(ch);
                    break;
                }
            }
            else if (ch == ')')
            {
               if(!stack.empty() && stack.top() == '(')
                   stack.pop();
               else
               {
                   stack.push(ch);
                   break;
               }
            }
        }
        if (stack.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}