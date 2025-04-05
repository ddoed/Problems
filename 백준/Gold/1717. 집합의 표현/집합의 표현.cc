#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr(1000001, -1);

int find(int x)
{
    if (arr[x] < 0) return x;
    return arr[x] = find(arr[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (arr[v] < arr[u]) swap(u, v);
    if (arr[u] == arr[v]) arr[u]--;
    arr[v] = u;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0;i < m;i++)
    {
        int x, a, b;
        cin >> x >> a >> b;

        if (x == 0) uni(a, b);
        else if (x == 1)
        {
            a = find(a);
            b = find(b);
            if (a == b) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}
