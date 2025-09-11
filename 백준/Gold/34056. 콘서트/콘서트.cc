#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q;
vector<long long> D;

void propagate(int start, int dir, long long x) {
    int idx = start;
    while (x > 0 && idx >= 1 && idx <= n) {
        if (D[idx] < x) {
            long long absorbed = D[idx];
            D[idx] *= 2;      // 두 배 강화
            x -= absorbed;    // 남은 소음
            idx += dir;       // 다음 벽으로 이동
        } else {
            D[idx] += x;      // 소음 전부 흡수
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    D.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> D[i];

    cin >> q;
    while (q--) {
        int t, c;
        cin >> t >> c;
        if (t == 1) {
            long long x;
            cin >> x;
            propagate(c, -1, x);   // 왼쪽 전파
            propagate(c+1, +1, x); // 오른쪽 전파
        } else {
            cout << D[c] << "\n";
        }
    }
    return 0;
}
