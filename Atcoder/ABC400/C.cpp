#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N;
    cin >> N;
    long long ans = 0;
    long long t;
    for (long long i = 1; i * i * 2 <= N; ++i) {
        if (i % 2 == 0) {
            continue;
        }
        t = i * i * 2;
        while (t <= N) {
            ans++;
            t *= 2;
        }
    }
    cout << ans << endl;
    return 0;
}