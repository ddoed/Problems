#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> arr(200002, -1);

int find(int x) {
    if (arr[x] < 0) return x;
    return arr[x] = find(arr[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (arr[v] < arr[u]) swap(u, v);
    arr[u] += arr[v];
    arr[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int f;
        cin >> f;

        fill(arr.begin(), arr.end(), -1);
        unordered_map<string, int> um;
        int idx = 0;

        for (int i = 0; i < f; i++) {
            string x, y;
            cin >> x >> y;

            if (um.find(x) == um.end()) um[x] = idx++;
            if (um.find(y) == um.end()) um[y] = idx++;

            int u = um[x];
            int v = um[y];

            uni(u, v);

            int root = find(u);
            cout << -arr[root] << '\n';
        }
    }

    return 0;
}
