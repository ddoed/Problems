#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    double r;
    cin >> n >> m >> r;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());

    // 밑변 후보 중복 없이 저장
    unordered_set<int> width_set;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            width_set.insert(abs(p[j] - p[i]));
        }
    }
    vector<int> widths(width_set.begin(), width_set.end());
    sort(widths.begin(), widths.end());

    // 깃대 정렬
    vector<int> f(m);
    for (int i = 0; i < m; i++) cin >> f[i];
    sort(f.begin(), f.end());

    // 실수 이분 탐색
    double left = 0, right = r;
    double result = -1;

    for (int iter = 0; iter < 100; iter++) {
        double mid = (left + right) / 2.0;
        bool canMake = false;
        double bestArea = -1;

        for (int w : widths) {
            double minH = (2.0 * mid) / w;
            auto it = lower_bound(f.begin(), f.end(), minH);
            if (it != f.end()) {
                double h = *it;
                double area = (w * h) / 2.0;
                if (area <= r) {
                    canMake = true;
                    bestArea = area;
                    break;
                }
            }
        }

        if (canMake) {
            result = bestArea;
            left = mid;
        } else {
            right = mid;
        }
    }

    if (result < 0) {
        cout << -1 << '\n';
    } else {
        cout << fixed;
        cout.precision(1);
        cout << result << '\n';
    }

    return 0;
}
