#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

#define int long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define INF LLONG_MAX

vector<pii> adj[4001];
int dFox[4001];
int dWolf[4001][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    fill(dFox + 1, dFox + n + 1, INF);
    for (int i = 1; i <= n; i++) 
    {
        dWolf[i][0] = INF;
        dWolf[i][1] = INF;
    }

    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        d *= 2;
        adj[a].push_back({ d, b });
        adj[b].push_back({ d, a });
    }

    priority_queue<pii, vector<pii>, greater<pii>> foxPQ;
    dFox[1] = 0;
    foxPQ.push({ 0, 1 });
    while (!foxPQ.empty()) {
        auto [curDist, cur] = foxPQ.top(); foxPQ.pop();
        if (dFox[cur] < curDist) continue;

        for (auto [nxtDist, nxt] : adj[cur]) {
            if (dFox[nxt] > dFox[cur] + nxtDist) {
                dFox[nxt] = dFox[cur] + nxtDist;
                foxPQ.push({ dFox[nxt], nxt });
            }
        }
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> wolfPQ;
    dWolf[1][0] = 0;
    wolfPQ.push({ 0, 1, 0 }); 

    while (!wolfPQ.empty()) {
        auto [curDist, cur, state] = wolfPQ.top(); wolfPQ.pop();
        if (dWolf[cur][state] < curDist) continue;

        for (auto [nxtDist, nxt] : adj[cur]) {
            int nState = 1 - state;
            int dist = (state == 0) ? curDist + nxtDist / 2 : curDist + nxtDist * 2;

            if (dWolf[nxt][nState] > dist) 
            {
                dWolf[nxt][nState] = dist;
                wolfPQ.push({ dist, nxt, nState });
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (dFox[i] < min(dWolf[i][0], dWolf[i][1])) cnt++;
    }

    cout << cnt;
    return 0;
}
