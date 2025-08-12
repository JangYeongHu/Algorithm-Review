#include <bits/stdc++.h>
using namespace std;
int arr[100001];
vector<int> tree[100001 * 4];

void init(int s, int e, int n) {
	if (s == e) {
		tree[n].push_back(arr[s]);
		return;
	}
	int m = (s + e) / 2;
	int lidx = n * 2, ridx = lidx + 1;
	init(s, m, lidx); init(m + 1, e, ridx);
	tree[n].resize(tree[lidx].size() + tree[ridx].size());
	merge(tree[lidx].begin(), tree[lidx].end(), tree[ridx].begin(), tree[ridx].end(), tree[n].begin());
}

int query(int s, int e, int n,int l,int r,int k) {
	if (e < l || s > r) return 0;
	if (s >= l && e <= r) return upper_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin();
	int m = (s + e) / 2;
	return query(s, m, n * 2, l, r, k) + query(m + 1, e, n * 2 + 1, l, r, k);
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}

	init(1, n, 1);

	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;

		int en = 1<<30, st = -en, mid, ans = en;
		while(st <= en) {
			mid = (st + en) / 2;
			int res = query(1, n, 1, i, j, mid);
			if (res >= k) {
				ans = min(ans, mid);
				en = mid - 1;
			}
			else st = mid + 1;
		}
		cout << ans << "\n";
	}

	return 0;
}