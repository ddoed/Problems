#include <iostream>

using namespace std;


int main() {
    int n, num;
    cin >> n;
    int count = n;

    for (int i = 0;i < n;i++)
    {
        cin >> num;
        
        if (num == 1 || num == 0)
        {
            count--;
            continue;
        }
        for (int i = 2;i < num;i++)
        {
            if (num % i == 0)
            {
                count--;
                break;
            }
        }
    }
    cout << count;
    
    return 0;
}