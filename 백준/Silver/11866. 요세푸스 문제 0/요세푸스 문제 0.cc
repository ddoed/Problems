#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    bool first = true;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    
    while (!q.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        if (first)
        {
            cout << "<" << k;
            first = false;
            q.pop();
            continue;
        }
        cout << ", " << q.front();
        q.pop();
    }
    cout << ">";


    return 0;
}