#include <bits/stdc++.h>
using namespace std;

long long arr[1'000'001];
long long tree[1'000'001 * 4];

void init(int s, int e, int n) {
	if (s == e) { tree[n] = arr[s]; return; }
	int m = (s + e) / 2;
	init(s, m, n * 2);
	init(m + 1, e, n * 2 + 1);

	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

void update(int s, int e, int n, long long k, long long x) {
	if (s == e) {
		tree[n] = x;
		return;
	}
	int m = (s + e) / 2;
	if (k <= m) update(s, m, n * 2, k, x);
	else update(m + 1, e, n * 2 + 1, k, x);

	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

long long get(int s, int e, int n, long long l, long long r) {
	if (e < l || s > r) return 0;
	if (s >= l && e <= r) return tree[n];

	int m = (s + e) / 2;
	return get(s, m, n * 2, l, r) + get(m + 1, e, n * 2 + 1, l, r);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k;  cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i + 1];

	init(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		long long a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			cout << get(1, n, 1, b, c) << "\n";
		}
	}

	return 0;
}