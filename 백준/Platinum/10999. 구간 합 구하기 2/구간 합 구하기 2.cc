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

int n, m, k;
int arr[1000001];
int segTree[4000001];
int lazy[4000001];

void updateLazy(int nodeL, int nodeR, int nodeNum) {
	if (lazy[nodeNum] != 0) {
		segTree[nodeNum] += (nodeR - nodeL + 1) * lazy[nodeNum];
		if (nodeL != nodeR) {
			lazy[nodeNum * 2] += lazy[nodeNum];
			lazy[nodeNum * 2 + 1] += lazy[nodeNum];
		}
		lazy[nodeNum] = 0;
	}
}

void update(int nodeL, int nodeR, int nodeNum, int L, int R, int val) {
	updateLazy(nodeL, nodeR, nodeNum);
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
	segTree[nodeNum] = segTree[nodeNum * 2] + segTree[nodeNum * 2 + 1];
}

int query(int nodeL, int nodeR, int nodeNum, int L, int R) {
	updateLazy(nodeL, nodeR, nodeNum);
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
	cin >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n - 1, 1);
	while (m+k--) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c, d;
			cin >> b >> c >> d;
			update(0, n-1, 1, b-1, c-1, d);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << query(0, n - 1, 1, b - 1, c - 1) << '\n';
		}
	}
}