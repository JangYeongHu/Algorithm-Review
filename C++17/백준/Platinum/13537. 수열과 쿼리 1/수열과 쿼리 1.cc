#include <bits/stdc++.h>
using namespace std;

int arr[100001];
vector<int> tree[100001 * 4];

void update(int s, int e, int n) {
	if (s == e) {
		tree[n].push_back(arr[s]);
		return;
	}
	int m = (s + e) / 2;
	int l_n = n * 2, r_n = n * 2 + 1, l_ind = 0, r_ind = 0;
	update(s, m, l_n);
	update(m+1, e, r_n);
	while (l_ind < tree[l_n].size() && r_ind < tree[r_n].size()) {
		if (tree[l_n][l_ind] < tree[r_n][r_ind]) {
			tree[n].push_back(tree[l_n][l_ind++]);
		}
		else {
			tree[n].push_back(tree[r_n][r_ind++]);
		}
	}
	while (l_ind < tree[l_n].size()) tree[n].push_back(tree[l_n][l_ind++]);
	while (r_ind < tree[r_n].size()) tree[n].push_back(tree[r_n][r_ind++]);
}

int get(int s, int e, int n, int l, int r, int k) {
	if (e < l || s > r) return 0;
	if (s >= l && e <= r) {
		int start = 0, end = tree[n].size()-1, mid = 0;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (tree[n][mid] <= k) start = mid + 1;
			else end = mid - 1;
		}
		return tree[n].size() - start;
	}
	int m = (s + e) / 2;
	return get(s, m, n*2, l, r, k) + get(m + 1, e, n*2+1, l, r, k);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i+1];
	update(1, n, 1);
	int m; cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		cout << get(1, n, 1, a, b, c) << "\n";
	}
	return 0;
}