#include <bits/stdc++.h>
using namespace std;

long long tree[100010 * 4];

long long get(int start, int end, int node, int a, int b) {
	if (b < start || a > end) return 0;
	if (a <= start && b >= end) return tree[node];
	int mid = (start + end) / 2;
	return get(start, mid, node * 2, a, b) + get(mid + 1, end, node * 2 + 1, a, b);
}

void update(int start, int end, int node,int ind, long long val) {
	if (ind < start || ind > end) return;
	if (start == end) { tree[node] = val; return; }
	int mid = (start + end) / 2;
	update(start, mid, node * 2, ind, val);
	update(mid + 1, end, node * 2 + 1, ind, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		update(1, n, 1, i+1,a);
	}
	while (q-- > 0) {
		int x, y, a;
		long long b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << get(1, n, 1, x, y) << "\n";
		update(1, n, 1, a,b);
	}
}