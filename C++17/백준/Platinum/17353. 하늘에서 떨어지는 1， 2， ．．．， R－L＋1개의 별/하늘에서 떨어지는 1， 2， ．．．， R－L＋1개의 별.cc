#include <bits/stdc++.h>
using namespace std;
struct node { long long l, r,cnt; };
long long arr[100001];
node lazy[100001 * 4];

void propagate(int n, int l, int r) {
	if (lazy[n].l == 0) return;
	if (l == r) arr[l] += lazy[n].l;
	else {
		long long size = r - l + 1;
		long long m = (1 + size) / 2;
		lazy[n * 2].l += lazy[n].l;
		lazy[n * 2].r += lazy[n].l + (m-1)*lazy[n].cnt;
		lazy[n * 2].cnt += lazy[n].cnt;

		lazy[n * 2 + 1].l += lazy[n].l + m * lazy[n].cnt;
		lazy[n * 2 + 1].r += lazy[n].r;
		lazy[n * 2+1].cnt += lazy[n].cnt;
	}
	lazy[n].l = lazy[n].r = lazy[n].cnt = 0;
}

void update(int n, int s, int e, int l, int r) {
	propagate(n, s, e);

	if (e < l || s > r) return;
	if (s >= l && e <= r) {
		int base = s - l;
		lazy[n].l += base + 1; lazy[n].r += base + (e - s + 1); lazy[n].cnt++;
		propagate(n, s, e);
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, l, r);
	update(n * 2 + 1, m + 1, e, l, r);
}

long long get(int n, int s, int e, int k) {
	propagate(n, s, e);
	if (k < s || k > e) return 0;
	if (s == e) return arr[k];
	int m = (s + e) / 2;
	return get(n * 2, s, m, k) + get(n * 2 + 1, m + 1, e, k);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i + 1];
	int q; cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			update(1, 1, n, b, c);
		}
		else {
			cout << get(1, 1, n, b) << "\n";
		}
	}
}