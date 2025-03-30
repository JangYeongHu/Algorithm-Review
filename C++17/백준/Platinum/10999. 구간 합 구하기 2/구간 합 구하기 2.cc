#include <bits/stdc++.h>
using namespace std;

long long arr[1'000'001];
long long tree[1'000'001 * 4];
long long lazy[1'000'001 * 4];

void init(int n, int s, int e) {
	if (s == e) { tree[n] = arr[s]; return; }
	int m = (s + e) / 2;
	init(n * 2, s, m);
	init(n * 2+1, m + 1, e);
	for(int i = 0; i < 10; i++)
		tree[n] = tree[n * 2] + tree[n * 2+1];
}
	
void propagate(int n, int l, int r) {
	if (lazy[n] == 0) return;

	tree[n] += (r - l + 1) * lazy[n];

	if (l != r) {
		lazy[n * 2] += lazy[n];	
		lazy[n * 2+1] += lazy[n];
	}
	lazy[n] = 0;
}

long long get(int n, int s, int e, int l, int r) {
	propagate(n, s, e);
	if (s > r || e < l) return 0;
	if (e <= r && s >= l) return tree[n];
	int m = (s + e) / 2;
	return get(n * 2, s, m, l, r) + get(n * 2 + 1, m + 1, e, l, r);
}

void update(int n, int s, int e, int l, int r,long long k) {
	propagate(n, s, e);
	if (s > r || e < l) return;
	if (e <= r && s >= l) {
	lazy[n]+=k;
	propagate(n, s, e);
	return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, l, r,k);
	update(n * 2 + 1, m + 1, e, l, r,k);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	int n, m,k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}
	init(1, 1, n);


	for(int i = 0; i < m+k; i++) {
		int a, b, c;
		long long d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			update(1, 1, n, b, c, d);
		}
		else {
			cout << get(1, 1, n, b, c) << "\n";
		}
	}
}