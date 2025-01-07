#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n;
    vector<int> input(n);
    vector<int> sums(n);

    for (int i = 0;i < n;i++)
    {
        cin >> input[i];
    }
    sums[0] = input[0];
    m = sums[0];
    for (int i = 1;i < input.size();i++)
    {
        sums[i] = max(input[i], sums[i - 1] + input[i]);
        if (sums[i] > m) m = sums[i];
    }
    cout << m;
    return 0;
}