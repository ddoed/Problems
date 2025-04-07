#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define aa 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long sum = 1;
    long long num = 1;
    bool flag = true;
    for (int i = 1;i < m + 1; i++)
    {
        num *= n;
        if (num <= aa && sum <= aa - num)
        {
            sum += num;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag) cout << sum;
    else cout << "inf";

    return 0;
}
