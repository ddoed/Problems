#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int w[101]= {0};
int v[101] = {0};
int DP[101][100001];

int n,k;

void dp(int n, int k)
{
    for (int limit = 1;limit <=k;limit++)
    {
        for (int row = 1;row<=n;row++)
        {
            if(w[row] > limit)
            {
                DP[row][limit] = DP[row-1][limit];
            }
            else
            {
                DP[row][limit] = max(DP[row-1][limit - w[row]] + v[row], DP[row-1][limit]);
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    
    for (int i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i];
    }
    
    for(int y=0;y<=n;y++)
    {
        DP[y][0] = 0;
    }
    for(int x=0;x<=k;x++)
    {
        DP[0][x] = 0;
    }
    
    dp(n,k);
    
    cout << DP[n][k];
    
    return 0;
}