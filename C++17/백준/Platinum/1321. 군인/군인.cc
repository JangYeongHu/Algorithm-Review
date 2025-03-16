#include <bits/stdc++.h>
using namespace std;

long long tree[500001 * 4];
long long arr[500001];

int get(int start, int end, int node, int a) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (tree[node * 2] >= a) return get(start, mid, node * 2, a);
	return get(mid + 1, end, node * 2 + 1, a - tree[node * 2]);
}

long long update(int start, int end, int node, int ind, int diff) {
	if (ind < start || ind > end) return tree[node];
	if (start == end) { tree[node] += diff;  return tree[node]; }
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, ind, diff) + update(mid + 1, end, node * 2 + 1, ind, diff);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { int a; cin >> a; arr[i + 1] = a; update(1, n, 1, i + 1, a); }
	int m;
	cin >> m;
	while (m-- > 0) {
		int q;
		cin >> q;
		if (q == 2) {
			int i;
			cin >> i;
			cout << get(1, n, 1, i) << "\n";
		}
		else {
			int i, a;
			cin >> i >> a;
			arr[i] += a;
			update(1, n, 1, i, a);
		}
	}
}