#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;

    int result = 400 % a;

    if (result != 0) cout << -1;
    else cout << 400 / a;


    return 0;
}
