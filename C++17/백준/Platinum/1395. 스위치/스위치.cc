#include <bits/stdc++.h>
bool swi[100001];
int tree[100001 * 4];
bool lazy_tree[100001 * 4];
using namespace std;

void lazy(int s, int e,int n, int l, int r) {
	if (lazy_tree[n]) tree[n] = (e - s + 1) - tree[n];
	if (s != e) {
		lazy_tree[n * 2] ^= lazy_tree[n];
		lazy_tree[n * 2 + 1] ^= lazy_tree[n];
	}
	lazy_tree[n] = 0;
}

int get(int s, int e, int n, int l, int r) {
	lazy(s, e,n, l, r);
	if (e < l || s > r) return 0;
	if (s >= l && e <= r) return tree[n];
	int m = (s + e) / 2;
	return get(s, m, n * 2, l, r) + get(m + 1, e, n * 2 + 1, l, r);
}

void update(int s, int e, int n, int l, int r) {
	lazy(s, e,n, l, r);
	if (e < l || s > r) return;
	if (s >= l && e <= r) {
		lazy_tree[n] = !lazy_tree[n];
		lazy(s, e,n, l, r);
		return;
	}
	int m = (s + e) / 2;
	update(s, m, n * 2, l, r);
	update(m + 1, e, n * 2 + 1, l, r);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n,m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int o, s, t; cin >> o >> s >> t;
		if (o) {
			cout << get(1, n, 1, s, t) << "\n";
		}
		else {
			update(1, n, 1, s, t);
		}
	}
	return 0;
}