#include <iostream>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;

    for (int i = 1; i <= 2; ++i) {
        int k = i * 2;

        int l = 1, r = n, best = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid <= n / mid && k <= n / (mid * mid))
            {
                best = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cnt += best;
    }

    cout << cnt << '\n';
    return 0;
}


/*
* n = 20
* x = 2^a * b^2
* k = 2^a
* 
* k = 2 인 경우
* 2*1*1 = 2
* 2*2*2 = 8
* 2*3*3 = 18
* 2*4*4 = 32 (x)
* 
* 즉 best = 3
* cnt += 3
* 
* k = 4
* 4*1*1 = 4
* 4*2*2 = 16
* 4*3*3 = 36 (x)
* 
* 즉 best = 2
* cnt += 2
* 
* 따라서 총 개수 (cnt)는 5
*/