#include <bits/stdc++.h>
using namespace std;
long long arr[100'001];
long long lazy[4 * 100'001];

void push(int n, int s, int e) {
	if (lazy[n] == 0) return;
	if (s == e) {
		arr[s] += lazy[n];
	}
	else {
		lazy[n * 2] += lazy[n];
		lazy[n * 2+1] += lazy[n];
	}
	lazy[n] = 0;
}

long long get(int n, int s, int e, int x) {
	push(n, s, e);
	if (s > x || e < x) return 0;
	if (s == e) return arr[x];
	int m = (s + e) / 2;
	return get(n * 2, s, m, x) + get(n * 2+1, m+1, e, x);
}

void update(int n, int s, int e, int l, int r, int k) {
	push(n, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		lazy[n] += k;
		push(n, s, e);
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, l, r, k);
	update(n * 2+1, m+1, e, l, r, k);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int nu; cin >> nu;
	for (int i = 0; i < nu; i++) cin >> arr[i + 1];
	int m; cin >> m;
	while (m--) {
		int n, i, j, k;
		cin >> n >> i;
		if (n == 1) {
			cin >> j >> k;
			update(1, 1, nu, i, j, k);
		}
		else {
			cout << get(1, 1, nu, i) << "\n";
		}
	}
}