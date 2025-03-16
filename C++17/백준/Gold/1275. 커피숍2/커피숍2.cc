#include <bits/stdc++.h>
using namespace std;

long long arr[100001];
long long tree[100001 * 4];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long get(int start, int end, int node, int a, int b) {
	if (a <= start && b >= end) return tree[node];
	if (b < start || a > end) return 0;
	int mid = (start + end) / 2;
	return get(start, mid, node * 2, a, b) + get(mid + 1, end, node * 2 + 1, a, b);
}

long long update(int start, int end, int node, int ind) {
	if (ind < start || ind > end) return tree[node];
	if (start == end) { return tree[node] = arr[ind]; }
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, ind) + update(mid+1, end, node * 2 + 1, ind);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i + 1];
	init(1, n, 1);
	while (q-- > 0) {
		int x, y, a,b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << get(1, n, 1, x, y) << "\n";
		arr[a] = b;
		update(1, n, 1, a);
	}
}