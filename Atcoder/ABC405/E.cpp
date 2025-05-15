#include <iostream>
#include <vector>
using namespace std;

#define MOD 998244353
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

const int MAX = 4000000;
vector<int> fact(MAX + 1), inv_fact(MAX + 1);

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = power(fact[i], MOD - 2);
    }
}

int comb(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int N = A + B + C + D;
    init();

    int ans = 0;
    for (int i = A; i <= A + B; i++) {
        int left_apples = comb(i - 1, A - 1);
        int right_bananas = comb(N - i, C);
        ans = (ans + left_apples * right_bananas % MOD) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
