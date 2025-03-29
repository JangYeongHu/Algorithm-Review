#include <bits/stdc++.h>
using namespace std;
int A[500001];
int tree[500001 * 4];
int lazy[500001 * 4];

int init(int n, int s, int e) {
	if (s == e) return tree[n] = A[s];
	int m = (s + e) / 2;
	return tree[n] = init(n * 2, s, m) ^ init(n * 2 + 1, m + 1, e);
}

void lazy_update(int n, int s,int e) {
	int leaf = (e - s + 1) % 2;
	if (lazy[n] == 0) return;
	tree[n] ^= lazy[n] * leaf;
	if (s != e) {
		lazy[n * 2] ^= lazy[n];
		lazy[n * 2 + 1] ^= lazy[n];
	}
	lazy[n] = 0;
}

int update(int n, int s, int e, int l, int r, int k) {
	lazy_update(n, s,e);
	if (r < s || l > e) return tree[n];
	int leaf = (e - s + 1) % 2;
	if (s >= l && e <= r) {
		if (s != e) {
			lazy[n * 2] ^= k;
			lazy[n * 2 + 1] ^= k;
		}
		return tree[n] ^= k * leaf; }
	int mid = (s + e) / 2;
	return tree[n] = update(n * 2, s, mid, l, r, k) ^ update(n * 2+1, mid + 1, e, l, r, k);
}

int get(int n, int s, int e, int l, int r) { 
	if (r < s || l > e) return 0;
	lazy_update(n, s,e);
	if (s >= l && e <= r) return tree[n];
	int m = (s + e) / 2;
	return get(n * 2, s, m, l, r) ^ get(n * 2 + 1, m + 1, e, l, r);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	init(1, 1, n);
	int m;
	cin >> m;
	while (m--) {
		int num, i, j, k;
		cin >> num >> i >> j;
		i++; j++;
		if (i > j) swap(i, j);
		if (num == 2) {
			cout << get(1, 1, n, i, j) << "\n";
		}
		else {
			cin >> k;
			update(1, 1, n, i, j, k);
		}
	}
}