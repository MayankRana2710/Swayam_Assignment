#include<bits/stdc++.h>
using namespace std;

const int INF_INT = numeric_limits<int>::max();

void buildSegTree(const vector<int>& a, vector<int>& seg, int node, int l, int r) {
	// ...build leaf or internal node...
	if (l == r) {
		seg[node] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	buildSegTree(a, seg, node << 1, l, mid);
	buildSegTree(a, seg, node << 1 | 1, mid + 1, r);
	seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
}

int rangeMinQuery(const vector<int>& seg, int node, int l, int r, int ql, int qr) {
	// ...no overlap...
	if (qr < l || ql > r) return INF_INT;
	// ...total overlap...
	if (ql <= l && r <= qr) return seg[node];
	int mid = (l + r) >> 1;
	return min(
		rangeMinQuery(seg, node << 1, l, mid, ql, qr),
		rangeMinQuery(seg, node << 1 | 1, mid + 1, r, ql, qr)
	);
}

int main() {
	
	int n, q;
	if (!(cin >> n >> q)) return 0;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<int> seg(4 * max(1, n), INF_INT);
	buildSegTree(a, seg, 1, 0, n - 1);

	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;

		// Detect and normalize: if both l and r are within [1..n], assume 1-based and convert.
		// Otherwise assume 0-based.
		int L = l, R = r;
		if (L >= 1 && L <= n && R >= 1 && R <= n) {
			// very likely 1-based indices
			L--; R--;
		}
		// clamp to valid range and fix order
		if (L < 0) L = 0;
		if (R < 0) R = 0;
		if (L >= n) L = n - 1;
		if (R >= n) R = n - 1;
		if (L > R) swap(L, R);

		int ans = rangeMinQuery(seg, 1, 0, n - 1, L, R);
		cout << ans << '\n';
	}

	return 0;
}
