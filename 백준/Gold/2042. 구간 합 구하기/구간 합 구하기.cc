#include <bits/stdc++.h>

using namespace std;

#define MOD 1e9+7
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

int N, M, K;
int arr[1000000];
int segTree[4 * 1000000];

int init(int nodeL, int nodeR, int num) {
	if (nodeL == nodeR) return segTree[num] = arr[nodeL];
	int mid = (nodeL + nodeR) / 2;
	return segTree[num] = init(nodeL, mid, num * 2) + init(mid + 1, nodeR, num * 2 + 1);
}

int sum(int nodeL, int nodeR, int num, int L, int R) {
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return segTree[num];
	int mid = (nodeL + nodeR) / 2;
	return sum(nodeL, mid, num * 2, L, R) + sum(mid + 1, nodeR, num * 2 + 1, L, R);
}

void update(int nodeL, int nodeR, int num, int idx, int diff) {
	if (idx < nodeL || nodeR < idx) return;
	segTree[num] += diff;
	if (nodeL == nodeR) return;

	int mid = (nodeL + nodeR) / 2;
	update(nodeL, mid, num * 2, idx, diff);
	update(mid + 1, nodeR, num * 2 + 1, idx, diff);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	init(0, N - 1, 1);

	for (int i = 0;i < M + K;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(0, N - 1, 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else if (a == 2) {
			cout << sum(0, N - 1, 1, b - 1, c - 1) << '\n';
		}
	}
}