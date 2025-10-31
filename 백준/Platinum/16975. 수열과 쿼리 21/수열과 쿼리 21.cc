#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1e9+7
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

int n, m;
int arr[100001];
int segTree[400001];
int lazy[400001];

void update(int nodeL, int nodeR, int nodeNum, int L, int R, int val) {
	if (lazy[nodeNum] != 0) {
		segTree[nodeNum] += (nodeR - nodeL + 1) * lazy[nodeNum];
		if (nodeL != nodeR) {
			lazy[nodeNum * 2] += lazy[nodeNum];
			lazy[nodeNum * 2 + 1] += lazy[nodeNum];
		}
		lazy[nodeNum] = 0;
	}
	if (nodeR < L || R < nodeL) return;
	if (L <= nodeL && nodeR <= R) {
		segTree[nodeNum] += (nodeR - nodeL + 1) * val;
		if (nodeL != nodeR) {
			lazy[nodeNum * 2] += val;
			lazy[nodeNum * 2 + 1] += val;
		}
		return;
	}
	int mid = (nodeL + nodeR) / 2;
	update(nodeL, mid, nodeNum * 2, L, R, val);
	update(mid + 1, nodeR, nodeNum * 2 + 1, L, R, val);
}

int query(int nodeL, int nodeR, int nodeNum, int L, int R) {
	if (lazy[nodeNum] != 0) {
		segTree[nodeNum] += (nodeR - nodeL + 1) * lazy[nodeNum];
		if (nodeL != nodeR) {
			lazy[nodeNum * 2] += lazy[nodeNum];
			lazy[nodeNum * 2 + 1] += lazy[nodeNum];
		}
		lazy[nodeNum] = 0;
	}
	if (nodeR < L || R < nodeL) return 0;
	if (L <= nodeL && nodeR <= R) {
		return segTree[nodeNum];
	}
	int mid = (nodeL + nodeR) / 2;
	return query(nodeL, mid, nodeNum * 2, L, R) + query(mid + 1, nodeR, nodeNum * 2 + 1, L, R);
}

void init(int nodeL, int nodeR, int nodeNum) {
	if (nodeL == nodeR) {
		segTree[nodeNum] = arr[nodeL];
		return;
	}
	int mid = (nodeL + nodeR) / 2;
	init(nodeL, mid, nodeNum * 2);
	init(mid + 1, nodeR, nodeNum * 2 + 1);
	segTree[nodeNum] = segTree[nodeNum * 2] + segTree[nodeNum * 2 + 1];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n - 1, 1);
	cin >> m;
	while (m--) {
		int num;
		cin >> num;
		if (num == 1) {
			int i, j, k;
			cin >> i >> j >> k;
			update(0, n-1, 1, i-1, j-1, k);
		}
		else {
			int x;
			cin >> x;
			cout << query(0, n - 1, 1, x - 1, x - 1) << '\n';
		}
	}
}