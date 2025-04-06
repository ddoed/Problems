#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> result(n, -1);
    unordered_map<int, int> um;
    stack<int> s;

    int maxCnt = 0;
    for (int i = 0;i < n;i++)
    {
        cin >> v[i];
        um[v[i]]++;
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && um[v[s.top()]] < um[v[i]]) {
            result[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0;i < n;i++)
    {
        cout << result[i] << ' ';
    }


    return 0;
}
