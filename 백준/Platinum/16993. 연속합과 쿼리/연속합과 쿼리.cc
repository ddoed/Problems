#include <bits/stdc++.h>

using namespace std;

#define MOD 1e9+7
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define NEG_INF -4e18
#define tiii tuple<int,int,int>
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1, 0 };

struct SegTree {
	int sum;
	int best;
	int leftMax;
	int rightMax;

	SegTree() {
		sum = 0;
		best = leftMax = rightMax = NEG_INF;
	}

	SegTree(int val) {
		sum = best = leftMax = rightMax = val;
	}

	SegTree operator+(const SegTree& other) {
		SegTree res;
		res.sum = sum + other.sum;
		res.best = max({ best, other.best, rightMax + other.leftMax });
		res.leftMax = max({ leftMax, sum + other.leftMax});
		res.rightMax = max({ other.rightMax, other.sum + rightMax});
		return res;
	}
};

int N, M;
vector<SegTree> segTree(400001);
vector<int> arr(100001);

SegTree query(int nodeL, int nodeR, int nodeNum, int L, int R) {
	if (nodeR < L || R < nodeL) return SegTree();
	if (L <= nodeL && nodeR <= R) {
		return segTree[nodeNum];
	}
	int mid = (nodeL + nodeR) / 2;
	return query(nodeL, mid, nodeNum * 2, L, R) + query(mid + 1, nodeR, nodeNum * 2 + 1, L, R);
}

void init(int nodeL, int nodeR, int nodeNum) {
	if (nodeL == nodeR) {
		segTree[nodeNum] = SegTree(arr[nodeL]);
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
	
	cin >> N;
	for (int i = 0;i < N; i++) {
		cin >> arr[i];
	}
	init(0, N-1, 1);
	cin >> M;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		SegTree s = query(0, N - 1, 1, a - 1, b - 1);
		cout << s.best << '\n';
	}
}