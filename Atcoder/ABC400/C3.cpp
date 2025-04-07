#include <iostream>
#include <cmath>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    int c1 = sqrtl(n / 2);
    int c2 = sqrtl(n / 4);
    cout << c1 + c2 << '\n';

    return 0;
}
